#include <iostream>
using namespace std;

// Define a structure for a node
struct node
{
    int data;
    node *next;
} *p = NULL, *q = NULL, *t = NULL;

// Function to push an element onto the stack
void push(int x)
{
    t = new node;
    t->data = x;
    t->next = NULL;
    if (p == NULL)
    {
        p = t;
    }
    else
    {
        t->next = p;
        p = t;
    }
}

// Function to pop an element from the stack
int pop()
{
    int x;
    if (p == NULL)
    {
        cout << "empty queue\n";
        return -1; // Indicate an error condition
    }
    else
    {
        q = p;
        x = q->data;
        p = p->next;
        delete (q);
        return x;
    }
}

int main()
{
    int n, c = 0, x;

    cout << "Enter the number of values to be pushed into stack: ";
    cin >> n;

    // Push elements into the stack
    while (c < n)
    {
        cout << "Enter the value to be entered into queue = ";
        cin >> x;
        push(x);
        c++;
    }

    cout << "\nRemoved Values:\n";

    // Pop and display elements
    while (true)
    {
        int val = pop();
        if (val != -1)
            cout << val << endl;
        else
            break;
    }

    int ch;
    while (1)
    {
        cout << "\n1. Push \n2. Pop \n3. Exit\n\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> x;
            push(x);
            break;
        case 2:
            x = pop();
            if (x != -1)
                cout << "Popped element: " << x << endl;
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}
