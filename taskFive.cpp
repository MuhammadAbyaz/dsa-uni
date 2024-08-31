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

bool twoDimensionalBinarySearch(int arr[][4], int target)
{
    for (int i = 0; i < 4; ++i)
    {
        if (arr[i][3] > target && binarySearch(arr[i], 0, 3, target) != -1)
            return true;
    }
    return false;
}
int main()
{
    int arr[][4] = {{1, 3, 5, 7}, {10, 11, 6, 20}, {23, 30, 34, 60}};
    cout
        << boolalpha
        << twoDimensionalBinarySearch(arr, 5);
    return 0;
}