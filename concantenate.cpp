#include <iostream>
using namespace std;

template <typename T>

class DLinkedList
{
private:
    struct Node
    {
        Node *next = nullptr;
        Node *previous = nullptr;
        T value = NULL;
    };
    void swap(Node *a, Node *b)
    {
        T temp = a->value;
        a->value = b->value;
        b->value = temp;
    }

public:
    Node *head;
    Node *tail;
    DLinkedList()
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
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }
    static Node *concatenate(Node *first, Node *second)
    {
        if (first == nullptr)
            return second;
        if (second == nullptr)
            return first;

        Node *newHead = first;
        Node *newTail = first;

        while (newTail->next != nullptr)
        {
            newTail = newTail->next;
        }

        newTail->next = second;

        if (second != nullptr)
        {
            second->previous = newTail;
        }

        return newHead;
    }
    void bubbleSort()
    {
        if (!head || !head->next)
            return;

        Node *current;
        Node *nextNode;

        int n = 0;
        current = head;
        while (current != nullptr)
        {
            n++;
            current = current->next;
        }

        for (int i = 0; i < n - 1; i++)
        {
            current = head;
            while (current != nullptr && current->next != nullptr)
            {
                nextNode = current->next;
                if (current->value < nextNode->value)
                {
                    swap(current, nextNode);
                }
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
    DLinkedList<int> DLinkedList1;
    DLinkedList1.append(2);
    DLinkedList1.append(4);
    DLinkedList1.append(6);
    DLinkedList1.append(8);
    DLinkedList1.append(10);
    DLinkedList<int> DLinkedList2;
    DLinkedList2.append(1);
    DLinkedList2.append(3);
    DLinkedList2.append(5);
    DLinkedList2.append(7);
    DLinkedList2.append(9);

    DLinkedList1.head = DLinkedList<int>::concatenate(DLinkedList1.head, DLinkedList2.head);
    DLinkedList1.bubbleSort();
    DLinkedList1.display();
}