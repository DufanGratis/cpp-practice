#include <iostream>
#include "Vector.h"
#include <cmath>
using namespace std;

int main()
{
    int s = -27;
    try
    {
        Vector v(s);
    }
    catch (length_error)
    {
        cout << "you intialize a negative size of vector v\n";
    }

    return 0;
}