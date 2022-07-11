#include <iostream>
#include "Vector.h"
#include <cmath>
using namespace std;

int main()
{
    int s = 5;
    Vector v(s);
    try
    {
        v[v.size()] = 7;
    }
    catch (out_of_range)
    {
        cout << "you access an out of range index of vector v\n";
    }

    return 0;
}