#include <iostream>
using namespace std;
class Abyaz_Lab06
{
private:
    int front;
    int rear;
    int *queue;
    int capacity;
    int size;

public:
    Abyaz_Lab06()
    {
        front = 0;
        rear = 0;
        size = 0;
        capacity = 100;
        queue = new int[capacity];
    }
    ~Abyaz_Lab06()
    {
        delete[] queue;
    }
    void enqueue(int value)
    {
        if (rear >= capacity)
        {
            cout << "Insertion not possible" << endl;
            return;
        }
        else if (size >= capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            size++;
            queue[rear++] = value;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        size--;
        return queue[front++];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void display()
    {
        for (int i = front; i < rear; ++i)
        {
            cout << queue[i] << " ";
        }
    }
};
int main()
{
    Abyaz_Lab06 queue;
    queue.enqueue(10);
    queue.enqueue(12);
    queue.enqueue(13);
    queue.enqueue(14);
    cout << "Dequeued: " << queue.dequeue() << " ";
    cout << "Dequeued: " << queue.dequeue() << " ";
    cout << endl;
    cout << "QUEUE: ";
    queue.display();
    return 0;
}