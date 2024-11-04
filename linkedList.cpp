#include <iostream>
using namespace std;

template <typename T>

class LinkedList
{
private:
    struct Node
    {
        Node *next = nullptr;
        T value = NULL;
    };
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void append(T value)
    {
        Node *newNode = new Node();
        newNode->value = value;
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        tail->next = newNode;
        tail = newNode;
    }
    Node *mergeList(Node *second)
    {
        if (head == nullptr)
            return second;
        if (second == nullptr)
            return head;
        Node *newList = new Node();
        if (head->value <= second->value)
        {
            newList = head;
            newList->next = mergeList(head->next, second);
        }
        else
        {
            newList = second;
            newList->next = mergeList(head, second->next);
        }
    }
    void removeDuplicates()
    {
        Node *current = head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->value == current->next->value)
            {
                Node *duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            }
            else
            {
                current = current->next;
            }
        }
    }
    void display()
    {
        if (head != nullptr)
        {
            Node *counter = head;
            while (counter != nullptr)
            {
                cout << counter->value << " ";
                counter = counter->next;
            }
        }
        else
        {
            cout << "Queue is empty";
        }
    }
};

int main()
{
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(2);
    list.append(3);
    list.append(3);
    list.append(4);
    list.display();
    cout << endl;
    list.removeDuplicates();
    list.display();
}