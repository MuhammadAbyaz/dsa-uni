#include <iostream>
#include <array>
using namespace std;

int binarySearch(int *arr, int lo, int hi, int target)
{
    if (lo > hi)
        return -1;
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] < target)
        return binarySearch(arr, mid + 1, hi, target);
    if (arr[mid] > target)
        return binarySearch(arr, lo, mid - 1, target);
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << binarySearch(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 0) << endl;
    cout << binarySearch(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 4) << endl;
}