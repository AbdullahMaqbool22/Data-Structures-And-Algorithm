#include <iostream>
using namespace std;

// Define a structure for a node in the queue
struct node
{
    int data;
    node *link;
};

// Class for implementing a circular queue using linked list
class circular_queue
{
private:
    node *rear; // Points to the rear of the queue

public:
    // Constructor to initialize an empty queue
    circular_queue()
    {
        rear = NULL;
    }

    // Function to insert an element into the queue
    void insert(int x)
    {
        node *t = new node; // Create a new node
        t->data = x;
        t->link = NULL;

        if (rear == NULL)
        {
            t->link = t; // For the first element, link it to itself
        }
        else
        {
            t->link = rear->link; // Link new node to the front
            rear->link = t;       // Update link of the rear node
        }

        rear = t; // Update rear pointer

        cout << "Element " << x << " inserted into the queue." << endl;
    }

    // Function to delete an element from the queue
    void del()
    {
        if (rear == NULL)
        {
            cout << "Queue Underflow. Cannot delete from an empty queue." << endl;
            return;
        }

        node *front = rear->link; // Get the front node
        int value = front->data;

        if (front == rear)
        {
            delete front;
            rear = NULL;
        }
        else
        {
            rear->link = front->link;
            delete front;
        }

        cout << "Element " << value << " deleted from the queue." << endl;
    }

    // Function to display the elements in the queue
    void display()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        node *front = rear->link; // Get the front node
        node *temp = front;

        cout << "Queue elements: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->link;
        } while (temp != front);

        cout << endl;
    }
};

int main()
{
    int choice, x;
    circular_queue cq;

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
            cq.insert(x);
            break;
        case 2:
            cq.del();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid Choice. Please try again." << endl;
        }
    }

    return 0;
}
