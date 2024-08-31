#include <iostream>
#include <array>
using namespace std;
class MedianFinder
{
private:
    int lastAppendedIndex;
    int lastSize;
    int *arr;

    void copyArr()
    {
        int *temp = new int[lastSize * 2];
        for (int i = 0; i < lastSize; ++i)
        {
            temp[i] = arr[i];
        }
        lastSize = lastSize * 2;
        delete[] arr;
        arr = temp;
    }

public:
    MedianFinder()
    {
        lastAppendedIndex = 0;
        lastSize = 5;
        arr = new int[lastSize];
    }
    void addNumber(int value)
    {
        if (lastAppendedIndex == lastSize)
        {
            copyArr();
        }
        arr[lastAppendedIndex] = value;
        lastAppendedIndex += 1;
    }
    float findMedian()
    {
        if (lastAppendedIndex % 2 != 0)
        {
            return arr[lastAppendedIndex / 2];
        }
        return (arr[(lastAppendedIndex - 1) / 2] + arr[(lastAppendedIndex) / 2]) / 2.0f;
    }
};

int main()
{
    MedianFinder medianFinder;
    medianFinder.addNumber(1);
    medianFinder.addNumber(2);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNumber(3);
    cout << medianFinder.findMedian() << endl;
    return 0;
}