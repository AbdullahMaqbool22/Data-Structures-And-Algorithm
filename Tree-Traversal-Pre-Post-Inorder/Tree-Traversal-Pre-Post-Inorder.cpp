#include <iostream>
using namespace std;

class bst
{
    struct node
    {
        int data;
        node *left;
        node *right;
    } *root; // Structure for a node in the binary search tree

public:
    int insert(int data);    // Function to insert a node in the BST
    void preorder(node *);   // Function to perform preorder traversal
    void inorder(node *);    // Function to perform inorder traversal
    void postorder(node *);  // Function to perform postorder traversal
    void display(int order); // Function to display the specified traversal

    bst()
    {
        root = NULL; // Constructor to initialize the root of the tree
    }
};

int bst ::insert(int data)
{
    if (root == NULL)
    {
        // If tree is empty, create the root node
        root = new node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return 0;
    }

    node *q = root;
    while (q != NULL)
    {
        if (data == q->data)
        {
            cout << "Already exist"; // If data already exists in the tree
            return 0;
        }
        else if (data < q->data)
        {
            if (q->left != NULL)
            {
                q = q->left; // Move to the left child if it exists
            }
            else
            {
                // Insert data as the left child if left child doesn't exist
                q->left = new node;
                q->left->data = data;
                q->left->left = NULL;
                q->left->right = NULL;
                return 0;
            }
        }
        else
        {
            if (q->right != NULL)
            {
                q = q->right; // Move to the right child if it exists
            }
            else
            {
                // Insert data as the right child if right child doesn't exist
                q->right = new node;
                q->right->data = data;
                q->right->left = NULL;
                q->right->right = NULL;
                return 0;
            }
        }
    }
    return 0;
}

void bst::preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->data << " "; // Print data of the current node
        preorder(p->left);      // Recur on left subtree
        preorder(p->right);     // Recur on right subtree
    }
}

void bst::inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);       // Recur on left subtree
        cout << p->data << " "; // Print data of the current node
        inorder(p->right);      // Recur on right subtree
    }
}

void bst::postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);     // Recur on left subtree
        postorder(p->right);    // Recur on right subtree
        cout << p->data << " "; // Print data of the current node
    }
}

void bst::display(int order)
{
    switch (order)
    {
    case 1:
        cout << "Inorder Traversal: ";
        inorder(root); // Call inorder traversal
        break;
    case 2:
        cout << "Preorder Traversal: ";
        preorder(root); // Call preorder traversal
        break;
    case 3:
        cout << "Postorder Traversal: ";
        postorder(root); // Call postorder traversal
        break;
    default:
        cout << "Invalid choice!" << endl; // Invalid choice for traversal type
    }
    cout << endl;
}

int main()
{
    bst tree; // Create an instance of the binary search tree

    // Insert some nodes into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Display in-order traversal
    tree.display(1);

    // Display pre-order traversal
    tree.display(2);

    // Display post-order traversal
    tree.display(3);

    return 0;
}