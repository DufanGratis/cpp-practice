#include <iostream>
using namespace std;

void copy_fct()
{
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10];

    for (auto i = 0; i != 10; ++i)
    {
        v2[i] = v1[i];
    }

    for (auto x : v2)
        cout << x << "\n";
}

void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto x : v)
        cout << x << "\n";

    for (auto x : {10, 21, 32, 43, 54, 65})
        cout << x << "\n";
}

void increment()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto &x : v)
        ++x;
}

int count_x(char *p, char x)
{
    if (p == nullptr)
        return 0;
    int count = 0;
    for (; *p != 0; ++p)
        if (*p == x)
            ++count;
    return count;
}

int main()
{
    copy_fct();
    print();
    char p[] = {'a', 'b', 'c', 'e', 'e'};
    int d = count_x(p, 'd');
    int e = count_x(p, 'e');
    cout << "char array contains the char d of " << d << " and the char e of " << e << "\n";

    return 0;
}