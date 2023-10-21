#include <iostream>
using namespace std;

// Define a structure for a node in a circular linked list
struct node
{
    int data;
    struct node *next;
} *p;

// Define a class for a circular linked list
class circular_list
{
public:
    // Function to create a new node
    void create_node(int value);

    // Function to add a new node after a specified position
    void add_after(int value, int position);

    // Function to delete a node with a specified value
    void delete_element(int value);

    // Function to display the circular linked list
    void display_list();

    // Constructor to initialize the pointer 'p' to NULL
    circular_list()
    {
        p = NULL;
    }
};

int main()
{
    int choice, element, position;
    circular_list cl;

    // Display menu and perform operations based on user's choice
    while (1)
    {
        cout << "1.Create Node" << endl;
        cout << "2.Add after" << endl;
        cout << "3.Delete" << endl;
        cout << "4.Display" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> element;
            cl.create_node(element);
            cout << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            cout << "Insert element after position: ";
            cin >> position;
            cl.add_after(element, position);
            cout << endl;
            break;
        case 3:
            if (p == NULL)
            {
                cout << "List is empty, nothing to delete" << endl;
                break;
            }
            cout << "Enter the element for deletion: ";
            cin >> element;
            cl.delete_element(element);
            cout << endl;
            break;
        case 4:
            cl.display_list();
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

// Function to create a new node
void circular_list::create_node(int value)
{
    node *t;
    t = new node;
    t->data = value;
    if (p == NULL)
    {
        p = t;
        t->next = p;
    }
    else
    {
        t->next = p->next;
        p->next = t;
        p = t;
    }
}

// Function to add a new node after a specified position
void circular_list::add_after(int val, int pos)
{
    if (p == NULL)
    {
        cout << "First create a node\n" // First Step to check for null value.
             << endl;
        return;
    }
    node *t, *s;
    s = p->next;
    for (int i = 0; i < pos - 1; i++)
    {
        s = s->next;
        if (s == p->next)
        {
            cout << "There are less than ";
            cout << pos << " in the list " << endl;
            return;
        }
    }
    t = new node;
    t->next = s->next;
    t->data = val;
    s->next = t;

    if (s == p)
    {
        p = t;
    }
}

// Function to delete a node with a specified value
void circular_list::delete_element(int value)
{
    node *t, *s;
    s = p->next;
    if (p->next == p && p->data == value)
    {
        t = p;
        p = NULL;
        free(t);
        return;
    }
    if (s->data == value)
    {
        t = s;
        p->next = s->next;
        free(t);
        return;
    }
    while (s->next != p)
    {
        if (s->next->data == value)
        {
            t = s->next;
            s->next = t->next;
            free(t);
            cout << "Element " << value;
            cout << "Element deleted" << endl;
            return;
        }
        s = s->next;
    }
    if (s->next->data == value)
    {
        t = s->next;
        s->next = p->next;
        free(t);
        p = s;
        return;
    }

    cout << "Element " << value << " not found in the list" << endl;
}

// Function to display the circular linked list
void circular_list::display_list()
{
    node *s;
    if (p == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    s = p->next;
    cout << "Circular linked list: ";
    while (s != p)
    {
        cout << s->data << " -> ";
        s = s->next;
    }
    cout << s->data << endl;
    cout << endl;
}