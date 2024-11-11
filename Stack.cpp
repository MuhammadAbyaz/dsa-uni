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
            newNode->next = top;
            top = newNode;
        }
    }
    T pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return T();
        }
        T value = top->value;
        top = top->next;
        return value;
    }
    void display()
    {
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl;
    s.display();
}