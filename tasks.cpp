#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Abyaz_Lab05
{
private:
    void merge(vector<int> &arr, int left, int mid, int right)
    {
        vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left;

        while (i < leftPart.size() && j < rightPart.size())
        {
            if (leftPart[i] <= rightPart[j])
            {
                arr[k++] = leftPart[i++];
            }
            else
            {
                arr[k++] = rightPart[j++];
            }
        }

        while (i < leftPart.size())
        {
            arr[k++] = leftPart[i++];
        }

        while (j < rightPart.size())
        {
            arr[k++] = rightPart[j++];
        }
    }

public:
    void nonRecursiveMergeSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int size = 1; size < n; size *= 2)
        {
            for (int left = 0; left < n; left += 2 * size)
            {
                int mid = min(left + size - 1, n - 1);
                int right = min(left + 2 * size - 1, n - 1);
                if (mid < right)
                {
                    merge(arr, left, mid, right);
                }
            }
        }
    }

    void nonRecursiveQuickSort(vector<int> &arr)
    {
        stack<int> stack;
        int left = 0;
        int right = arr.size() - 1;

        stack.push(left);
        stack.push(right);

        while (!stack.empty())
        {
            right = stack.top();
            stack.pop();
            left = stack.top();
            stack.pop();

            if (left < right)
            {
                int pivot = arr[left];
                int i = left;
                int j = right;
                while (i < j)
                {
                    while (i < j && arr[j] >= pivot)
                    {
                        j--;
                    }
                    while (i < j && arr[i] <= pivot)
                    {
                        i++;
                    }
                    if (i < j)
                    {
                        swap(arr[i], arr[j]);
                    }
                }
                swap(arr[left], arr[i]);

                stack.push(left);
                stack.push(i - 1);

                stack.push(i + 1);
                stack.push(right);
            }
        }
    }
    vector<vector<int>> mergeIntervals(vector<vector<int>> time)
    {
        vector<vector<int>> result;
        sort(time.begin(), time.end());
        for (int i = 0; i < time.size(); ++i)
        {
            if (i == 0 || time[i][0] > result.back()[1])
            {
                result.push_back(time[i]);
            }
            else
            {
                result.back()[1] = max(result.back()[1], time[i][1]);
            }
        }
        return result;
    }
    int harmoniousSequence(vector<int> sequence)
    {
        unordered_map<int, int> freq;
        int maxLength = 0;
        for (int val : sequence)
        {
            freq[val]++;
        }
        for (auto it : freq)
        {
            if (freq.find(it.first + 1) != freq.end())
            {
                maxLength = max(maxLength, freq[it.first] + freq[it.first + 1]);
            }
        }
        return maxLength;
    }
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        map<int, int> passengerChange;

        for (const auto &trip : trips)
        {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            passengerChange[from] += numPassengers;
            passengerChange[to] -= numPassengers;
        }

        int currentPassengers = 0;

        for (const auto &[location, change] : passengerChange)
        {
            currentPassengers += change;
            if (currentPassengers > capacity)
            {
                return false;
            }
        }

        return true;
    }
};
int main()
{
    Abyaz_Lab05 generalClass;
    vector<vector<int>> trips = {{2, 1, 5},
                                 {3, 3, 7}};
    cout << boolalpha << generalClass.carPooling(trips, 4);
    return 0;
}

// vector<int> arr2 = {34, 7, 23, 32, 5, 62};
// generalClass.nonRecursiveQuickSort(arr2);

// cout << "Sorted array: ";
// for (int num : arr2)
// {
//     cout << num << " ";
// }
// cout << endl;
// vector<int> arr = {34, 7, 23, 32, 5, 62};
// generalClass.nonRecursiveMergeSort(arr);

// cout << "Sorted array: ";
// for (int num : arr)
// {
//     cout << num << " ";
// }
// cout << endl;

// vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
// vector<vector<int>> result = generalClass.mergeIntervals(intervals);
// for (int i = 0; i < result.size(); ++i)
// {
//     for (int val : result[i])
//     {
//         cout << val << " ";
//     }
// }
// vector<int> sequence = {1,
//                         3,
//                         2,
//                         2,
//                         5,
//                         2,
//                         3,
//                         7};
// cout << generalClass.harmoniousSequence(sequence);
