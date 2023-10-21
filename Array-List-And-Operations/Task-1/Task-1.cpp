#include <iostream>
using namespace std;

int main()
{
    int n[10] = {32, 27, 64, 18, 95, 14, 90, 70, 60, 37};
    cout << "Element "
         << "\t"
         << " Value" << endl;
    int i = 0;
    while (i < 10)
    {
        cout << i << "\t          " << n[i] << endl;
        i++;
    }

    return 0;
}
