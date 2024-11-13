#include <iostream>
using namespace std;
template <typename T>

class BTree
{
private:
    struct Node
    {
        Node *right;
        Node *left;
        T value;
        Node(T val) : right(nullptr), left(nullptr), value(val) {}
    };
    Node *root;

public:
    BTree() : root(nullptr) {}
    Node *getRoot()
    {
        return root;
    }
    void insert(T val)
    {
        Node *newNode = new Node(val);
        if (root == nullptr) // If the tree is empty
        {
            root = newNode;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            else
            {
                q.push(current->left);
            }

            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }
    void preOrder(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->value << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void inOrder(Node *root)
    {
        if (root != nullptr)
        {
            preOrder(root->left);
            cout << root->value << " ";
            preOrder(root->right);
        }
    }
    void postOrder(Node *root)
    {
        if (root != nullptr)
        {
            preOrder(root->left);
            preOrder(root->right);
            cout << root->value << " ";
        }
    }
    bool isMirror(Node *left, Node *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }

        return (left->value == right->value) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric()
    {
        if (root == nullptr)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool levelOrderSearch(T val)
    {
        if (root == nullptr)
        {
            return false;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            if (current->value == val)
            {
                return true;
            }

            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }

        return false;
    }
};

int main()
{
    BTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    cout << boolalpha << tree.levelOrderSearch(30) << endl;
    tree.preOrder(tree.getRoot());
    cout << endl;
    tree.inOrder(tree.getRoot());
    cout << endl;
    tree.postOrder(tree.getRoot());
    cout << endl;
    cout << boolalpha << tree.isSymmetric() << endl;
}