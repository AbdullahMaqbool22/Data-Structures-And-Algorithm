#include <iostream>
using namespace std;

int main()
{
    char grade;

    cout << "Enter your grade (A, B, C, D, or F): ";
    cin >> grade;

    switch (grade)
    {
    case 'A':
        cout << "Excellent! You've got an A." << endl;
        break;
    case 'B':
        cout << "Good job! You've got a B." << endl;
        break;
    case 'C':
        cout << "You've got a C. Keep it up." << endl;
        break;
    case 'D':
        cout << "You've got a D. You might want to work harder." << endl;
        break;
    case 'F':
        cout << "Oops! You've got an F. You should seek help." << endl;
        break;
    default:
        cout << "Invalid grade. Please enter A, B, C, D, or F." << endl;
    }

    return 0;
}
