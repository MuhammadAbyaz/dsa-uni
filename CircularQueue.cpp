#include <iostream>
using namespace std;

template <typename T>
class CircularQueue
{
private:
    struct Node
    {
        T value = NULL;
        Node *next = nullptr;
    };
    Node *head;
    Node *tail;

public:
    CircularQueue()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~CircularQueue()
    {
        if (head != nullptr)
        {
            Node *counter = head;
            while (counter != tail)
            {
                Node *temp = counter->next;
                delete counter;
                counter = temp;
            }
            delete counter;
        }
    }
    void enqueue(T val)
    {
        Node *newNode = new Node();
        newNode->value = val;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        tail->next = head;
    }
    void display()
    {
        if (head != nullptr)
        {
            Node *counter = head;
            while (counter != tail)
            {
                cout << counter->value;
                counter = counter->next;
            }
            cout << counter->value;
        }
        else
        {
            cout << "Queue is empty";
        }
    }
};
int main()
{
    CircularQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.display();
    return 0;
}