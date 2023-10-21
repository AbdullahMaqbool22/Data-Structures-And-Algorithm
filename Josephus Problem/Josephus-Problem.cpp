#include <iostream>
using namespace std;

// Recursive function to solve the Josephus problem
int josephus(int n, int k)
{
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}

int main()
{
    int n, k;
    cout << "Enter the total number of people (n): ";
    cin >> n;
    cout << "Enter the interval (k): ";
    cin >> k;

    // Calculate the position of the last person standing
    int survivor = josephus(n, k) + 1;

    cout << "The last person standing is at position: " << survivor << endl;

    return 0;
}