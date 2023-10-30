#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Declare and initialize vectors
    vector<int> num = {1, 2, 3, 4};     // Vector with elements 1, 2, 3, 4
    vector<int> num1 = {1, 2, 3, 4, 5}; // Vector with elements 1, 2, 3, 4, 5
    vector<int> num2(5, 6);             // Vector with 5 elements, each initialized to 6 [6, 6, 6, 6, 6]

    // Add and remove elements
    num.push_back(5); // Add element 5 at the end
    num.pop_back();   // Remove last element

    // Access and modify elements
    cout << "Element at index 3: " << num.at(3) << endl; // Access element at index 3
    num.at(3) = 75;                                      // Change element at index 3 to 75

    // Check the size of vector
    cout << "Size of num: " << num.size() << endl; // Print size of vector num

    // Clear the vector
    num.clear(); // Clear all elements

    // Check if vector is empty before accessing front and back
    if (!num.empty())
    {
        cout << "First element: " << num.front() << ", Last element: " << num.back() << endl; // Print first and last elements
    }
    else
    {
        cout << "Vector is empty." << endl; // Vector is empty
    }

    // Print elements of num using a range-based for loop
    cout << "Elements of num: ";
    for (int i : num)
    {
        cout << i << " "; // Print elements of num
    }
    cout << endl;

    // Print elements of num1 using a range-based for loop
    cout << "Elements of num1: ";
    for (int i : num1)
    {
        cout << i << " "; // Print elements of num1
    }
    cout << endl;

    // Print elements of num2 using a range-based for loop
    cout << "Elements of num2: ";
    for (int i : num2)
    {
        cout << i << " "; // Print elements of num2
    }

    return 0;
}
