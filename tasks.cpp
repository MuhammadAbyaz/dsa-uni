#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Abyaz_lab04
{
private:
public:
    void bubble_sort(int *arr, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            bool flag = false;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    flag = true;
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            if (!flag)
                break;
        }
    }
    void bubble_sort_analytics(int *arr, int n)
    {
        int comparisions = 0;
        int swaps = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - i; ++j)
            {
                comparisions++;
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swaps++;
                }
            }
        }
        cout << "Bubble Sort Analytics Report" << endl;
        cout << "Comparisions: " << comparisions << endl;
        cout << "Swaps: " << swaps << endl;
    }
    void insertion_sort(int *arr, int n)
    {
        for (int i = 1; i < n; ++i)
        {
            int j = i - 1;
            int temp = arr[i];
            while ((arr[j] > temp) && (j >= 0))
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
    void insertion_sort_analytics(int *arr, int n)
    {
        int comparisions = 0;
        int swaps = 0;
        for (int i = 1; i < n; ++i)
        {
            int j = i - 1;
            int temp = arr[i];
            comparisions++;
            while ((arr[j] > temp) && (j >= 0))
            {
                comparisions++;
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
        cout << "Insertion Analytics Report" << endl;
        cout << "Comparisions: " << comparisions << endl;
        cout << "Swaps: " << swaps << endl;
    }
    void selection_sort(int *arr, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr[minIndex], arr[i]);
        }
    }
    void selection_sort_analytics(int *arr, int n)
    {
        int comparisions = 0;
        int swaps = 0;

        for (int i = 0; i < n; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j)
            {
                comparisions++;
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swaps++;
            swap(arr[minIndex], arr[i]);
        }
        cout << "Selection Sort Analytics Report" << endl;
        cout << "Comparisions: " << comparisions << endl;
        cout << "Swaps: " << swaps << endl;
    }
    int max_toys(int *arr, int k, int size)
    {
        selection_sort(arr, size);
        int sum = 0;
        int toys = 0;
        int i = 0;
        while (sum < k && i < size)
        {
            sum += arr[i];
            if (sum <= k)
            {
                toys += 1;
            }
            i += 1;
        }
        return toys;
    }
    void sort_options(int *arr, int n)
    {
        int option;
        cout << "1: Selection Sort" << endl;
        cout << "2: Bubble Sort" << endl;
        cout << "3: Insertion Sort" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            selection_sort_analytics(arr, n);
            break;
        case 2:
            bubble_sort_analytics(arr, n);
            break;
        case 3:
            bubble_sort_analytics(arr, n);
        default:
            cout << "Select valid options!!" << endl;
            break;
        }
    }
    int findMaximum(int end, vector<int> &arr)
    {
        int idx = 0;
        for (int i = 0; i <= end; ++i)
        {
            if (arr[i] > arr[idx])
                idx = i;
        }
        return idx;
    }
    int rotate(int end, vector<int> &arr)
    {
        int flips = 1;
        int i = 0;
        int j = end;
        while (i <= j)
        {
            flips += 1;
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        return flips;
    }
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> flips;
        int size = arr.size() - 1;
        for (int i = size; i >= 0; --i)
        {
            int maxIndex = findMaximum(i, arr);
            rotate(maxIndex, arr);
            flips.push_back(maxIndex + 1);
            rotate(i, arr);
            flips.push_back(i + 1);
        }
        return flips;
    }

    void counting_sort(int *arr, int size)
    {
        int red = 0;
        int blue = 0;
        int white = 0;
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == 0)
                red++;
            else if (arr[i] == 1)
                white++;
            else
                blue++;
        }
        for (int i = 0; i < size; ++i)
        {
            if (red > 0)
            {
                arr[i] = 0;
                red--;
            }
            else if (white > 0)
            {
                arr[i] = 1;
                white--;
            }
            else
            {
                arr[i] = 2;
            }
        }
    }
    void perform_analysis()
    {
        srand(time(0));
        int size = rand() % 100 + 1;
        int arr1[size];
        int arr2[size];
        int arr3[size];
        for (int i = 0; i < size; ++i)
        {
            int randValue = rand() % 100 + 1;
            arr1[i] = randValue;
            arr2[i] = randValue;
            arr3[i] = randValue;
        }
        cout << "1: Perform analysis automated" << endl;
        cout << "2: Perform analysis manual" << endl;
        cout << "3: Exit" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            bubble_sort_analytics(arr1, size);
            selection_sort_analytics(arr2, size);
            insertion_sort_analytics(arr3, size);
            return;
        }
        case 2:
        {
            int size;
            cout << "Enter size of array: ";
            cin >> size;
            int *arr = new int[size];
            for (int i = 0; i < size; ++i)
            {
                cout << "Enter value at " << i + 1 << " position: ";
                cin >> arr[i];
            }
            sort_options(arr, size);
            delete[] arr;
            return;
        }
        default:
        {
            cout << "Please enter valid value";
            return;
        }
        }
    }
};

int main()
{
    Abyaz_lab04 sorter;
    int arr[6] = {2, 0, 2, 1, 1, 0};
    sorter.counting_sort(arr, 6);
    for (int i = 0; i < 6; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}