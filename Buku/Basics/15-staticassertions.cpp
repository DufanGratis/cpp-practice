#include <iostream>
using namespace std;

int main()
{
    constexpr double C = 2.0;
    double s = 3.0;
    constexpr double local_max = 3.0;
    // static_assert(speed < C, "can't go that fast");
    static_assert(local_max < C, "can't go that fast");

    return 0;
}