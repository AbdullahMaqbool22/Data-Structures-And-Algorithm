#include <iostream>
using namespace std;

// Function to recursively find the sum of elements in an array
int BinarySum(int A[], int i, int n)
{
    if (n == 1)
    {
        return A[i]; // base case: return the element
    }
    else
    {
        // recursive case: divide the array in half and sum both halves
        return BinarySum(A, i, n / 2) + BinarySum(A, i + n / 2, n / 2);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the sum of elements
    cout << "Sum of elements in the array: " << BinarySum(arr, 0, n) << endl;

    return 0;
}
