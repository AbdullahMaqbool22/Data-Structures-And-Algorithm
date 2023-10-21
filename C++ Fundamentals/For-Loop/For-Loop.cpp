#include <iostream>
using namespace std;
int arr[] = {16, 2, 77, 40, 12071};
int n, result = 0;
int main()
{
    for (n = 0; n < 5; n++)
    {
        result += arr[n];
    }
    cout << "Your result is: " << result;
    return 0;
}