// This is a C++ program that implements a singly linked list with various operations.
// Let's go through the code with comments explaining each section.

#include <iostream> // Include necessary header files
#include <conio.h>
#include <stdlib.h>

using namespace std;

class list // Define a class named 'list'
{
    struct node // Define a structure 'node' to represent each element in the list
    {
        int data;   // Data of the node
        node *link; // Pointer to the next node
    } *p;           // 'p' is a pointer to the first node of the list

public:
    void inslast(int);    // Function to insert a node at the end
    void insbeg(int);     // Function to insert a node at the beginning
    void delelement(int); // Function to delete a specific element
    void delbeg();        // Function to delete the first element
    void dellast();       // Function to delete the last element
    void disp();          // Function to display the elements of the list
    int seek(int);        // Function to search for an element and return its position

    list() // Constructor of the class
    {
        p = NULL; // Initialize the list as empty
    }

    ~list(); // Destructor to free memory allocated for nodes
};

// Function to insert a node at the end of the list
void list::inslast(int x)
{
    node *q, *t;
    if (p == NULL) // If the list is empty
    {
        p = new node;   // Create the first node
        p->data = x;    // Set its data
        p->link = NULL; // It's the only node, so no link
    }
    else
    {
        q = p;
        while (q->link != NULL) // Traverse the list to find the last node
            q = q->link;
        t = new node;   // Create a new node
        t->data = x;    // Set its data
        t->link = NULL; // It's the last node, so no link
        q->link = t;    // Link the last node to the new node
    }

    cout << "Inserted Successfully at the end…\n";
    disp(); // Display the list after insertion
}

// Function to insert a node at the beginning of the list
void list::insbeg(int x)
{
    node *q;
    q = p;        // Store the current first node
    p = new node; // Create a new node to be the first
    p->data = x;  // Set its data
    p->link = q;  // Link it to the previous first node
    cout << "\n Inserted successfully at the beginning . .";
    disp(); // Display the list after insertion
}

// Function to delete a specific element from the list
void list::delelement(int x)
{
    node *q, *r;
    q = p;
    if (q->data == x) // If the first node contains the element to be deleted
    {
        p = q->link; // Update the first node
        delete q;    // Free memory of the deleted node
        return;
    }
    r = q;
    while (q != NULL)
    {
        if (q->data == x)
        {
            r->link = q->link; // Link the previous node to the next node
            delete q;          // Free memory of the deleted node
            return;
        }
        r = q;
        q = q->link;
    }
    cout << "\nElement you entered " << x << " is not found..";
}

// Function to delete the first element of the list
void list::delbeg()
{
    cout << "\nThe list before deletion:";
    disp();
    node *q;
    q = p;
    if (q == NULL) // If the list is already empty
    {
        cout << "\nNo data is present..";
        return;
    }
    p = q->link; // Update the first node
    delete q;    // Free memory of the deleted node
    return;
}

// Function to delete the last element of the list
void list::dellast()
{
    cout << "\n The list before deletion: ";
    disp();
    node *q, *t;
    q = p;
    if (q == NULL) // If the list is already empty
    {
        cout << "\nThere is no data in the list..";
        return;
    }
    if (q->link == NULL) // If there's only one element in the list
    {
        p = q->link; // Update the first node (which will be NULL)
        delete q;    // Free memory of the deleted node
        return;
    }

    while (q->link->link != NULL) // Traverse to the second last node
        q = q->link;
    q->link = NULL; // Remove the link to the last node
    return;
}

// Destructor to free memory allocated for nodes
list ::~list()
{
    node *q;
    if (p == NULL) // If the list is empty
        return;

    while (p != NULL) // Loop to delete all nodes
    {
        q = p->link; // Store the link to the next node
        delete p;    // Free memory of the current node
        p = q;       // Move to the next node
    }
}

// Function to display the elements of the list
void list::disp()
{
    node *q;
    q = p;
    if (q == NULL) // If the list is empty
    {
        cout << " \nNo data is in the list..";
        return;
    }
    cout << "\nThe items present in the list are :";
    while (q != NULL) // Loop to print all elements
    {
        cout << " " << q->data; // Print the data of the current node
        q = q->link;            // Move to the next node
    }
    cout << endl;
}

// Function to search for an element and return its position
int list::seek(int value)
{
    node *temp;
    temp = p;
    int position = 0;
    while (temp != NULL)
    {
        if (temp->data == value) // If element is found
            return position + 1; // Return its position (1-based indexing)
        else
        {
            temp = temp->link;
            position = position + 1; // Move to the next node
        }
    }
    cout << " Element " << value << "Not Found"; // If element is not found
    return 0;                                    // Return 0 indicating element not found
}

int main()
{
    list l; // Create an object of the class

    int ch, v, p, ps;

    do
    {
        cout << "\nOperations on List.. \n";
        cout << "\n1. Insertion\n2. Deletion\n3. Display\n4. Seek\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\n1. Insertion at the beginning\n2. Insertion at the end";
            cout << "\n3. Enter your choice:";
            cin >> ps;
            cout << "\nEnter the value to insert: ";
            cin >> v;

            switch (ps)
            {
            case 1:
                l.insbeg(v);
                break;
            case 2:
                l.inslast(v);
                break;
            default:
                cout << "\nThe choice is invalid..";
                return 0;
            }
            break;

        case 2:
            cout << "\n1. Delete the first element\n2. Delete the last element";
            cout << "\n3 Enter the element to delete from list";
            cout << "\nEnter your choice: ";
            cin >> ps;

            switch (ps)
            {
            case 1:
                l.delbeg();
                cout << "\nThe list after deletion: ";
                l.disp();
                break;
            case 2:
                l.dellast();
                cout << "\nThe list after deletion";
                l.disp();
                break;
            case 3:
                l.disp();
                cout << "\nEnter the element to delete :";
                cin >> v;
                l.delelement(v);
                cout << "\nThe list after deletion: ";
                l.disp();
                break;
            default:
                cout << "\nThe option is invalid..";
                break;
            }
            break;

        case 3:
            l.disp();
            break;

        case 4:
            l.disp();
            cout << "\nEnter the element to search: ";
            cin >> v;
            cout << "\nThe position of the element " << v << " is " << l.seek(v);
            break;

        case 5:
            exit(1);

        default:
            cout << "\nThe option is invalid..";
            return 0;
        }
    } while (ch != 5);

    return 0;
}