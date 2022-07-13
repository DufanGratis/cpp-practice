#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5> x{1, 2, 3, 4, 5};

    cout << "Array x size: " << x.size() << endl;
    cout << "Array x max size: " << x.size() << endl;
    cout << "Array x distance: " << distance(x.begin(), x.end()) << endl;

    // For iteration
    cout << "x for auto = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    cout << "x for i = ";
    for (int i = 0; i != x.size(); ++i)
        cout << x[i] << " - ";
    cout << endl;

    // While iteration
    cout << "x bgn = ";
    auto elem = x.begin();
    while (elem != x.end())
    {
        cout << *elem << " - ";
        ++elem;
    }
    cout << endl;

    cout << "x adv = ";
    auto adv = x.begin();
    while (adv != x.end())
    {
        cout << *adv << " - ";
        advance(adv, 1);
    }
    cout << endl;

    x.~array();

    return 0;
}