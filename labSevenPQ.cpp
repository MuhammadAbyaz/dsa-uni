#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Abyaz_Lab07
{
private:
    bool flag;
    priority_queue<int>
        maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    Abyaz_Lab07(bool maxFlag = true) : flag(maxFlag)
    {
        if (flag)
            maxHeap = priority_queue<int>();
        else
            minHeap = priority_queue<int, vector<int>, greater<int>>();
    }
    void pushing(int element)
    {
        if (flag)
            maxHeap.push(element);
        else
            minHeap.push(element);
    }
    void massPushing(vector<int> elements)
    {
        if (flag)
        {
            for (int element : elements)
            {
                maxHeap.push(element);
            }
        }
        else
        {
            for (int element : elements)
            {
                minHeap.push(element);
            }
        }
    }
    int poping()
    {
        if (flag)
        {
            int val = maxHeap.top();
            maxHeap.pop();
            return val;
        }
        else
        {
            int val = minHeap.top();
            minHeap.pop();
            return val;
        }
    }
    void massPoping()
    {
        if (flag)
        {
            cout << "Max-Heap: ";
            while (!maxHeap.empty())
            {
                cout << maxHeap.top() << " ";
                maxHeap.pop();
            }
            cout << endl;
        }
        else
        {
            cout << "Min-Heap: ";
            while (!minHeap.empty())
            {
                cout << minHeap.top() << " ";
                minHeap.pop();
            }
            cout << endl;
        }
    }
};
int main()
{
    Abyaz_Lab07 q(false);
    q.pushing(10);
    q.pushing(20);
    q.pushing(30);
    q.pushing(40);
    q.pushing(50);
    q.pushing(60);
    q.pushing(70);
    q.pushing(80);
    q.massPoping();
    return 0;
}
