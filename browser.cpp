#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string url;
    Node *next;
    Node *prev;
    Node(string u) : url(u), next(nullptr), prev(nullptr) {}
};

class BrowserHistory
{
private:
    Node *head;
    Node *current;

public:
    BrowserHistory(string homepage)
    {
        head = new Node(homepage);
        current = head;
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps)
    {
        while (steps > 0 && current->prev != nullptr)
        {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps)
    {
        while (steps > 0 && current->next != nullptr)
        {
            current = current->next;
            steps--;
        }
        return current->url;
    }

    ~BrowserHistory()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main()
{

    BrowserHistory *browserHistory = new BrowserHistory("homepage.com");

    browserHistory->visit("google.com");
    browserHistory->visit("leetcode.com");

    cout << browserHistory->back(1) << endl;
    cout << browserHistory->back(1) << endl;
    cout << browserHistory->forward(1) << endl;
    browserHistory->visit("youtube.com");
    cout
        << browserHistory->forward(2) << endl;

    delete browserHistory;
    return 0;
}
