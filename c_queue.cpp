#include <iostream>
using namespace std;

class Abyaz_Lab06
{
private:
    int front;
    int rear;
    int *queue;
    int size;
    int capacity;

public:
    Abyaz_Lab06()
    {
        front = 0;
        rear = 0;
        capacity = 100;
        queue = new int[capacity];
        size = 0;
    }
    ~Abyaz_Lab06()
    {
        delete[] queue;
    }
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(int value)
    {
        if (isFull())
        {
            throw runtime_error("Queue is Full");
        }
        queue[rear] = value;
        size += 1;
        rear = (rear + 1) % capacity;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        int temp = queue[front];
        size -= 1;
        front = (front + 1) % capacity;
        return temp;
    }
    void display()
    {
        for (int i = front; i != rear; i = (i + 1) % capacity)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Abyaz_Lab06 circular_queue;
    circular_queue.enqueue(10);
    circular_queue.enqueue(20);
    circular_queue.enqueue(30);
    circular_queue.enqueue(40);
    cout << circular_queue.dequeue() << " ";
    cout << circular_queue.dequeue() << " ";
    cout << "Circular Queue: ";
    circular_queue.display();
    return 0;
}