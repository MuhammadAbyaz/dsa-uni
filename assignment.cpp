#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        Node *next;
        T value;
        Node(T val) : next(nullptr), value(val) {}
    };
    Node *head;
    Node *tail;
    int size;

    void swap(Node *first, Node *second)
    {
        T temp = first->value;
        first->value = second->value;
        second->value = temp;
    }

    Node *merge(Node *left, Node *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        Node *dummy = new Node(0);
        Node *current = dummy;

        while (left && right)
        {
            if (left->value <= right->value)
            {
                current->next = left;
                left = left->next;
            }
            else
            {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left)
            current->next = left;

        else
            current->next = right;

        Node *sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }

    Node *mergeSort(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *right = slow->next;
        slow->next = nullptr;

        Node *left = mergeSort(head);
        right = mergeSort(right);

        return merge(left, right);
    }

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList()
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete current;
        head = nullptr;
    }
    void insert(T val)
    {
        Node *newNode = new Node(val);
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
        size++;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }

    void bubbleSort()
    {
        Node *current;
        for (int i = 0; i < size; ++i)
        {
            current = head;
            for (int j = 0; j < size - i - 1; ++j)
            {
                if (current->value > current->next->value)
                {
                    swap(current, current->next);
                }
                current = current->next;
            }
        }
    }
    void selectionSort()
    {
        Node *fixed = head;
        Node *moveable;
        for (int i = 0; i < size; ++i)
        {
            moveable = fixed;
            Node *minNode = fixed;
            for (int j = i; j < size; ++j)
            {
                if (moveable->value < minNode->value)
                {
                    minNode = moveable;
                }
                moveable = moveable->next;
            }
            swap(fixed, minNode);
            fixed = fixed->next;
        }
    }
    void insertionSort()
    {
        if (!head || !head->next)
            return;
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *current = head;
        for (int i = 0; i < size - 1; ++i)
        {
            if (current->value <= current->next->value)
            {
                current = current->next;
            }
            else
            {
                Node *toInsert = current->next;
                current->next = toInsert->next;

                Node *pos = dummy;
                while (pos->next && pos->next->value < toInsert->value)
                {
                    pos = pos->next;
                }
                toInsert->next = pos->next;
                pos->next = toInsert;
            }
        }
        head = dummy->next;
        delete dummy;
    }
    void mergeSort()
    {
        head = mergeSort(head);
    }
};

int main()
{
    LinkedList<int> l1;
    l1.insert(20);
    l1.insert(5);
    l1.insert(3);
    l1.insert(1);
    l1.insert(40);
    // l1.bubbleSort();
    // l1.selectionSort();
    // l1.insertionSort();
    // l1.mergeSort();
    l1.display();
}