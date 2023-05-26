/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every
node
v. Search a value.
*/

#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
class tree
{
public:
    node *root = new node();
    void createRoot(int key, node *root)
    {
        root->data = key;
        root->left = NULL;
        root->right = NULL;
    }
    void insertnode(int key, node *root)
    {
        node *newNode = new node();
        newNode->data = key;
        if (root->data > key)
        {
            if (root->left == NULL)
            {
                root->left = newNode;
            }
            else
                insertnode(key, root->left);
        }
        else if (root->data < key)
        {
            if (root->right == NULL)
            {
                root->right = newNode;
            }
            else
                insertnode(key, root->right);
        }
        else
        {
            cout << "Duplicate Entries Not Allowed";
        }
    }
    void search(int key, node *a)
    {
        if (a->data == key)
        {
            cout << "Key Found" << endl;
        }
        else if (a->data > key)
        {
            if (a->left == NULL)
                cout << "Key Not Found" << endl;
            else
                search(key, a->left);
        }
        else if (a->data < key)
        {
            if (a->right == NULL)
                cout << "Key Not Found" << endl;
            else
                search(key, a->right);
        }
    }
    void swapnodes(node *a)
    {
        node *temp;
        if (root == NULL)
        {
            cout << "Tree Not Found" << endl;
        }
        else if (a == NULL)
        {
            return;
        }
        else
        {
            temp = a->left;
            a->left = a->right;
            a->right = temp;
            swapnodes(a->left);
            swapnodes(a->right);
        }
    }
    void minelement(node *current)
    {
        while (current->left != NULL && current != NULL)
        {
            current = current->left;
        }

        cout << "Minimum Element is " << current->data << endl;
    }
    void maxelement(node *current)
    {
        while (current->right != NULL && current != NULL)
        {
            current = current->right;
        }

        cout << "Maximum Element is " << current->data << endl;
    }
    void display(node *a)
    {
        if (a != NULL)
        {
            display(a->left);
            cout << a->data << endl;
            display(a->right);
        }
    }
};
int main()
{
    tree t;
    t.createRoot(44, t.root);
    t.insertnode(12, t.root);
    t.insertnode(26, t.root);
    t.insertnode(36, t.root);
    t.insertnode(49, t.root);
    t.insertnode(55, t.root);
    t.insertnode(64, t.root);
    t.display(t.root);
    t.search(67, t.root);
    // t.swapnodes(t.root);
    // t.display(t.root);
    t.minelement(t.root);
    // t.display(t.root);
    t.maxelement(t.root);
    return 0;
}
