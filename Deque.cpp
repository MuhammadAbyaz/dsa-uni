#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *prev;
    Node *next;

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class Deque
{
private:
    Node<T> *front;
    Node<T> *back;
    int size;

public:
    Deque() : front(nullptr), back(nullptr), size(0) {}

    ~Deque()
    {
        while (!isEmpty())
        {
            popFront();
        }
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }

    void pushFront(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            front = back = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void pushBack(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            front = back = newNode;
        }
        else
        {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node<T> *temp = front;
        front = front->next;
        if (front != nullptr)
        {
            front->prev = nullptr;
        }
        else
        {
            back = nullptr;
        }
        delete temp;
        size--;
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node<T> *temp = back;
        back = back->prev;
        if (back != nullptr)
        {
            back->next = nullptr;
        }
        else
        {
            front = nullptr;
        }
        delete temp;
        size--;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node<T> *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Deque<int> intDeque;

    intDeque.pushBack(10);
    intDeque.pushBack(20);
    intDeque.pushFront(5);
    intDeque.pushBack(30);

    cout << "Deque of integers after pushing elements: ";
    intDeque.display();

    intDeque.popFront();
    intDeque.popBack();

    cout << "Deque of integers after popping front and back: ";
    intDeque.display();

    return 0;
}
