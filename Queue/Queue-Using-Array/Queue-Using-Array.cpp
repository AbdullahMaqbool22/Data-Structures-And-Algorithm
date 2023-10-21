#include <iostream>
using namespace std;

class queue
{
    int qu[5];
    int front;
    int rear;

public:
    void insert(int);
    void dequeue();
    void display();
    queue()
    {
        front = -1;
        rear = -1;
    }
};

// Function to insert an element into the queue
void queue::insert(int x)
{
    if (front == -1)
    {
        front = 0;
    }
    if (rear >= 4)
    {
        cout << "\n Queue Overflow" << endl;
    }
    else
    {
        qu[++rear] = x;
        cout << "Element " << x << " inserted into the queue." << endl;
    }
}

// Function to delete an element from the queue
void queue::dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "\nQueue Underflow. Cannot delete from an empty queue." << endl;
        return;
    }
    else
    {
        cout << "\nElement deleted from queue is: " << qu[front++] << endl;
    }
}

// Function to display the elements in the queue
void queue::display()
{
    if (front == -1)
    {
        cout << "\nQueue is empty" << endl;
    }
    else
    {
        cout << "\nQueue elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << qu[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int ch, val;
    queue q;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Insert element into queue" << endl;
        cout << "2. Delete element from queue" << endl;
        cout << "3. Display all the elements of queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter the element to insert: ";
            cin >> val;
            q.insert(val);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "\nExiting..." << endl;
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (ch != 4);

    return 0;
}