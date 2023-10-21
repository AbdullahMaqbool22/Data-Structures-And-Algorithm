#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Define a structure for a node in the doubly linked list
struct node
{
    int data;   // Data of the node
    node *next; // Pointer to the next node
    node *prev; // Pointer to the previous node
} *p;           // Global pointer to the first node

// Define a class for a doubly linked list
class double_llist
{
public:
    // Function to create a new node
    void create_list(int value);

    // Function to add a new node after a specified position
    void add_after(int value, int position);

    // Function to delete a node with a specified value
    void delete_element(int value);

    // Function to display the doubly linked list
    void display_dlist();

    // Constructor to initialize the global pointer to NULL
    double_llist()
    {
        p = NULL;
    }
};

// Main function
int main()
{
    int choice, element, position;
    double_llist dl;

    // Display menu and perform operations based on user's choice
    while (1)
    {
        cout << endl;
        cout << "1.Insert" << endl;
        cout << "2.Add after" << endl;
        cout << "3.Delete" << endl;
        cout << "4.Display" << endl;
        cout << "5.Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> element;
            dl.create_list(element);
            cout << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            cout << "Insert Element after position: ";
            cin >> position;
            dl.add_after(element, position);
            cout << endl;
            break;

        case 3:
            if (p == NULL)
            {
                cout << "List empty, nothing to delete" << endl;
                break;
            }
            cout << "Enter the element for deletion: ";
            cin >> element;
            dl.delete_element(element);
            cout << endl;
            break;
        case 4:
            dl.display_dlist();
            cout << endl;
            break;
        case 5:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}

// Function to create a new node
void double_llist::create_list(int value)
{
    node *q, *t;

    // Allocate memory for a new node
    t = new node;

    // Set data and pointers
    t->data = value;
    t->next = NULL;

    // If the list is empty, set previous pointer to NULL and update global pointer
    if (p == NULL)
    {
        t->prev = NULL;
        p = t;
    }
    else
    {
        // Otherwise, traverse to the end and add the new node
        q = p;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = t;
        t->prev = q;
    }
}

// Function to add a new node after a specified position
void double_llist::add_after(int value, int position)
{
    if (p == NULL)
    {
        cout << "List is empty, First create the list." << endl;
        return;
    }

    node *tmp, *q;

    // Initialize a pointer to the first node
    q = p;

    // Traverse to the specified position
    for (int i = 0; i < position - 1; i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout << "There are less than ";
            cout << position << " elements." << endl;
            return;
        }
    }

    // Allocate memory for the new node
    tmp = new node;

    // Set data
    tmp->data = value;

    if (q->next == NULL)
    {
        // If the position is at the end, adjust pointers accordingly
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        // Otherwise, adjust pointers to insert the new node
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }

    cout << "Element inserted" << endl;
}

// Function to delete a node with a specified value
void double_llist ::delete_element(int value)
{
    node *tmp, *q;

    // If the first node contains the value to delete
    if (p->data == value)
    {
        tmp = p;
        p = p->next;
        p->prev = NULL;
        cout << "Element Deleted" << endl;

        // Free memory for the node
        delete tmp;
        return;
    }

    q = p;
    while (q->next->next != NULL)
    {
        if (q->next->data == value)
        {
            // If the value is found, adjust pointers to remove the node
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout << "Element Deleted" << endl;

            // Free memory for the node
            delete tmp;
            return;
        }
        q = q->next;
    }

    // If the last node contains the value to delete
    if (q->next->data == value)
    {
        tmp = q->next;

        // Remove the node
        q->next = NULL;
        cout << "Element Deleted" << endl;

        // Free memory for the node
        delete tmp;
        return;
    }

    cout << "Element " << value << " not found" << endl;
}

// Function to display the doubly linked list
void double_llist::display_dlist()
{
    node *q;

    if (p == NULL)
    {
        cout << "List Empty" << endl;
        return;
    }

    q = p;
    cout << "The Doubly Link List is: ";
    while (q != NULL)
    {
        cout << q->data << " - ";
        q = q->next;
    }

    cout << endl;
}

