#include <iostream>
using namespace std;

// Recursive function to find the sum of elements in an array
int findSum(int a[], int n)
{
    if (n <= 0)
    {
        return 0; // Base case: sum of zero elements is 0
    }
    return (findSum(a, n - 1) + a[n - 1]); // Recursive step: Add current element to sum of the rest
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the sum of elements
    cout << "Sum of elements in the array: " << findSum(arr, n) << endl;

    return 0;
}
