#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueue
{
private:
    Node *front;
    Node *rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
            rear->next = front;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }

        cout << "Enqueued: " << value << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        if (front == rear)
        {
            delete front;
            front = rear = nullptr;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        cout << "Dequeued from the front." << endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *temp = front;
        cout << "Queue elements: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    ~CircularQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    queue.dequeue();
    queue.display();

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.dequeue();

    return 0;
}
