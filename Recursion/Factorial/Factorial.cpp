#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n)
{
    if (n == 0)
    {
        return 1; // Base case: factorial of 0 is 1
    }
    else
    {
        return n * factorial(n - 1); // Recursive step
    }
}

int main()
{
    int n;

    // Get user input
    cout << "Enter a positive integer: ";
    cin >> n;

    // Check if the input is valid
    if (n >= 0)
    {
        // Calculate and display factorial
        cout << "Factorial of " << n << " = " << factorial(n);
    }
    else
    {
        cout << "Error: Input must be a non-negative integer.";
    }

    return 0;
}
