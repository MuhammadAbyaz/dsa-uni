#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    struct Node
    {
        T value = NULL;
        Node *next = nullptr;
    };
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }
    void push(T value)
    {
        Node *newNode = new Node();
        newNode->value = value;
        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            top->next = newNode;
        }
    }
    T pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        T value = top->value;
        top = top->next;
        return value;
    }
    void display()
    {
        Node *current = top;
        while (current->next != nullptr)
        {
            cout << current->value << " ";
        }
    }
};