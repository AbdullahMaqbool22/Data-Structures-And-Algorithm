#include <iostream>
using namespace std;

// Define a structure for a node in the queue
struct node
{
    int data;
    node *link;
};

// Class for implementing a queue using linked list
class queue_list
{
private:
    node *front; // Points to the front of the queue
    node *rear;  // Points to the rear of the queue

public:
    // Constructor to initialize an empty queue
    queue_list()
    {
        front = NULL;
        rear = NULL;
    }

    // Function to insert an element into the queue
    void insert(int x)
    {
        node *t = new node; // Create a new node
        t->data = x;
        t->link = NULL;

        if (front == NULL)
        {
            front = t;
            rear = t;
        }
        else
        {
            rear->link = t;
            rear = t;
        }

        cout << "Element " << x << " inserted into the queue." << endl;
    }

    // Function to delete an element from the queue
    void del()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow. Cannot delete from an empty queue." << endl;
            return;
        }

        node *q = front;
        int value = q->data;

        front = front->link;
        delete q;

        cout << "Element " << value << " deleted from the queue." << endl;
    }

    // Function to display the elements in the queue
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        node *q = front;
        cout << "Queue elements: ";
        while (q != NULL)
        {
            cout << q->data << " ";
            q = q->link;
        }
        cout << endl;
    }
};

int main()
{
    int choice, x;
    queue_list ql;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Element into the Queue" << endl;
        cout << "2. Delete Element from the Queue" << endl;
        cout << "3. Display the Queue" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> x;
            ql.insert(x);
            break;
        case 2:
            ql.del();
            break;
        case 3:
            ql.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid Choice. Please try again." << endl;
        }
    }

    return 0;
}
