#include <iostream>
using namespace std;

class Stack
{
    int stk[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top > 3)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        stk[++top] = x;
        cout << "Inserted " << x << endl;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Deleted " << stk[top--] << endl;
    }

    void display()
    {
        if (top < 0)
        {
            cout << "Stack empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << stk[i] << " ";
        cout << endl;
    }
};

int main()
{
    int ch;
    Stack st;

    while (1)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter your choice: ";
        cin >> ch;

        // Added a check for valid input
        if (cin.fail())
        {
            cout << "Invalid input. Exiting..." << endl;
            break;
        }

        switch (ch)
        {
        case 1:
            int x;
            cout << "Enter the element: ";
            cin >> x;
            st.push(x);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
