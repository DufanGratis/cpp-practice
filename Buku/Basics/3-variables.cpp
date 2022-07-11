#include <iostream>
using namespace std;

void int_double()
{
    double d = 2.2;
    int i = 7;
    d = d + i;
    i = d * i;
    cout << "d = " << d << " and i = " << i << "\n";
}

int main()
{
    int_double();

    return 0;
}