#include <iostream>
using namespace std;

int main()
{
    int a, b, yrs = 0;
    cin >> a >> b;

    while (a <= b)
    {
        a = a * 3;
        b = b * 2;
        yrs++;
    }

    cout << yrs << endl;
    return 0;
}