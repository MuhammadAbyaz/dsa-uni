#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    Node *insert(Node *node, int value)
    {
        if (!node)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int sumOfNodes(Node *node)
    {
        if (!node)
            return 0;
        return node->data + sumOfNodes(node->left) + sumOfNodes(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insert(root, value);
    }

    void preorderTraversal()
    {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorderTraversal()
    {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    static Node *findLCA(Node *root, int n1, int n2)
    {
        if (!root)
            return nullptr;

        if (n1 < root->data && n2 < root->data)
            return findLCA(root->left, n1, n2);

        if (n1 > root->data && n2 > root->data)
            return findLCA(root->right, n1, n2);

        return root;
    }

    Node *findLCA(int n1, int n2)
    {
        return findLCA(root, n1, n2);
    }

    int sumOfAllNodes()
    {
        return sumOfNodes(root);
    }
};

int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.preorderTraversal();
    bst.postorderTraversal();

    int n1 = 20,
        n2 = 40;
    Node *lca = bst.findLCA(n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA does not exist." << endl;

    int sum = bst.sumOfAllNodes();
    cout << "Sum of all nodes: " << sum << endl;

    return 0;
}
