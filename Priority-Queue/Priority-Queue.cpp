#include <iostream>
using namespace std;

// Define a structure for a node in the priority queue
struct node
{
    int data;
    int priority; // Added priority field
    node *link;
};

// Class for implementing a priority queue using linked list
class priority_queue_list
{
private:
    node *front; // Points to the front of the priority queue

public:
    // Constructor to initialize an empty priority queue
    priority_queue_list()
    {
        front = NULL;
    }

    // Function to insert an element with priority into the priority queue
    void insert(int x, int priority)
    {
        node *t = new node; // Create a new node
        t->data = x;
        t->priority = priority;
        t->link = NULL;

        if (front == NULL || priority > front->priority)
        {
            t->link = front;
            front = t;
        }
        else
        {
            node *q = front;
            while (q->link != NULL && q->link->priority >= priority)
            {
                q = q->link;
            }
            t->link = q->link;
            q->link = t;
        }

        cout << "Element " << x << " with priority " << priority << " inserted into the priority queue." << endl;
    }

    // Function to delete the element with the highest priority from the priority queue
    void del()
    {
        if (front == NULL)
        {
            cout << "Priority Queue Underflow. Cannot delete from an empty priority queue." << endl;
            return;
        }

        node *q = front;
        int value = q->data;

        front = front->link;
        delete q;

        cout << "Element " << value << " deleted from the priority queue." << endl;
    }

    // Function to display the elements in the priority queue
    void display()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        node *q = front;
        cout << "Priority Queue elements: ";
        while (q != NULL)
        {
            cout << q->data << " (Priority: " << q->priority << ") ";
            q = q->link;
        }
        cout << endl;
    }
};

int main()
{
    int choice, x, priority;
    priority_queue_list pq;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Element into the Priority Queue" << endl;
        cout << "2. Delete Element from the Priority Queue" << endl;
        cout << "3. Display the Priority Queue" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> x;
            cout << "Enter the priority: ";
            cin >> priority;
            pq.insert(x, priority);
            break;
        case 2:
            pq.del();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid Choice. Please try again." << endl;
        }
    }

    return 0;
}
