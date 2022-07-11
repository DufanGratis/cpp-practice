#include <iostream>
#include "Vector.h"
#include <cmath>
using namespace std;

double sqrt_sum(Vector &v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); ++i)
        sum += sqrt(v[i]);
    return sum;
}

int main()
{
    int s = 1;
    Vector v(s);
    double sumrt = sqrt_sum(v);
    cout << "vector v has the size of " << v.size() << " with the first element of " << v[0] << " and with the sum of square root of each element in vector v is " << sumrt << "\n";

    return 0;
}