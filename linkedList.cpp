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
    Node *getHead()
    {
        return head;
    }
    void setHead(Node *h)
    {
        head = h;
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
    static Node *mergeList(Node *first, Node *second)
    {
        if (first == nullptr)
            return second;
        if (second == nullptr)
            return first;
        Node *newList = new Node();
        if (first->value <= second->value)
        {
            newList = first;
            newList->next = mergeList(first->next, second);
        }
        else
        {
            newList = second;
            newList->next = mergeList(first, second->next);
        }
        return newList;
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
            cout << "List is empty";
        }
    }
    static Node *reverseList(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    static bool compareLists(Node *head1, Node *head2)
    {
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->value != head2->value)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    static bool isPalindrome(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        Node *reversedList = reverseList(head);

        bool isPalin = compareLists(head, reversedList);

        return isPalin;
    }
};

int main()
{
    LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(2);
    list1.append(3);
    list1.append(3);
    list1.append(4);
    cout << "Before Removing Duplicates" << endl;
    list1.display();
    cout << endl;
    list1.removeDuplicates();
    cout << "After Removing Duplicates" << endl;
    list1.display();
    cout << endl;

    LinkedList<int> first;
    first.append(1);
    first.append(2);
    first.append(4);
    LinkedList<int> second;
    second.append(1);
    second.append(2);
    second.append(4);

    first.setHead(LinkedList<int>::mergeList(first.getHead(), second.getHead()));
    cout << "After merging" << endl;
    first.display();

    LinkedList<char> word;
    word.append('d');
    word.append('a');
    word.append('d');

    cout << endl;
    cout << boolalpha << LinkedList<char>::isPalindrome(word.getHead()) << endl;
}