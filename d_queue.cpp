#include <iostream>
using namespace std;

class Abyaz_Lab06
{
private:
    int front;
    int rear;
    int size;
    int capacity;
    int *queue;

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
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void insertFront(int value)
    {
        if (isFull())
        {
            throw runtime_error("Queue is full");
        }
        size++;
        front = ((front - 1) + capacity) % capacity;
        queue[front] = value;
    }
    void insertRear(int value)
    {
        if (isFull())
        {
            throw runtime_error("Queue is full");
        }
        queue[rear] = value;
        size++;
        rear = ((rear + 1) % capacity);
    }
    int deleteFront()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is Empty");
        }
        front = (front + 1) % capacity;
        int temp = queue[front];
        size--;
        return temp;
    }
    int deleteRear()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is Empty");
        }
        rear = ((rear - 1) + capacity) % capacity;
        int temp = queue[rear];
        size--;
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
    Abyaz_Lab06 d_queue;
    d_queue.insertFront(10);
    d_queue.insertFront(20);
    d_queue.insertRear(30);
    d_queue.insertRear(40);
    cout << "Front Deleted " << " ";
    cout << d_queue.deleteFront();
    cout << endl;
    cout << "Rear Deleted" << " ";
    cout << d_queue.deleteRear();
    cout << endl;
    d_queue.display();
    return 0;
}