#include <iostream>
using namespace std;

void const_constexpr()
{
    const int dmv = 17;
    int var = 17;
    constexpr double max1 = 1.4 * dmv;
    // constexpr double max2 = 1.4 * var;
    const double max3 = 1.4 * dmv;
    cout << "max1 = " << max1 << " and mas3 = " << max3 << "\n";
}

int main()
{
    const_constexpr();

    return 0;
}