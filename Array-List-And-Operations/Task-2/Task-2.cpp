#include <iostream>
using namespace std;

int main()
{
    int i, min_val, max_val, list[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the value for place: " << i + 1 << "\n";
        cin >> list[i];
    }
    min_val = list[0];
    for (int i = 0; i < 10; i++)
        if (min_val > list[i])
            min_val = list[i];
    cout << "\nminimum value:" << min_val << "\n";
    max_val = list[0];
    for (int i = 0; i < 10; i++)
        if (max_val < list[i])
            max_val = list[i];
    cout << "maximum value: " << max_val << "\n";

    return 0;
}