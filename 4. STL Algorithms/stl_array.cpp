#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int main()
{
    array<int, 5> x{6, 7, 8, 9, 1};
    array<int, 5> y{1, 2, 3, 4, 5};
    array<int, 5> z{1, 2, 3, 2, 1};

    cout << "x = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    cout << "y = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    auto print = [](const int &n)
    {
        cout << n << " - ";
    };

    // Nonmodifying

    cout << "x print = ";
    for_each(x.begin(), x.end(), print);
    cout << endl;

    for_each(y.begin(), y.end(), [](int &n)
             { n++; });
    cout << "y print = ";
    for_each(y.begin(), y.end(), print);
    cout << endl;

    auto a = count(x.begin(), x.end(), 1);
    auto b = count(x.begin(), x.end(), 2);

    cout << "Total of element 1 in x is = " << a << endl;
    cout << "Total of element 2 in x is = " << b << endl;

    int n = 5;
    auto a_itr = find(x.begin(), x.end(), n);
    if (a_itr != x.end())
        cout << "Array x contains the element " << n << endl;
    else
        cout << "Array x does not contains the element " << n << endl;

    cout << "z = ";
    for (auto elem : z)
        cout << elem << " x ";
    cout << endl;
    auto eq = equal(z.begin(), z.begin() + z.size() / 2, z.rbegin());
    cout << "Array z is " << ((eq) ? "" : "not ") << "a palindrome" << endl;

    // mismatch

    // search

    // Modifying

    // copy

    // unique

    // remove

    // replace

    // rotate

    // random_shuffle

    // partition

    // Permutation

    z.fill(-1);

    cout << "z fill = ";
    for (auto elem : z)
        cout << elem << " x ";
    cout << endl;

    x.swap(y);

    cout << "x swap 1 = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    cout << "y swap 1 = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    swap(y, x);
    cout << "x swap 2 = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    cout << "y swap 2 = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    // Sorting and Searching

    for (auto elem : x)
    {
        if (binary_search(y.begin(), y.end(), elem))
        {
            cout << "Element " << elem << " is in array y" << endl;
        }
        else
        {
            cout << "Element " << elem << " is not in array y" << endl;
        }
    }

    auto l = lower_bound(x.begin(), x.end(), 6);
    auto u = upper_bound(x.begin(), x.end(), 6);

    cout << "lower bound = " << *l << endl;
    cout << "upper bound = " << *u << endl;

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << "x sort = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    cout << "y sort = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    vector<int> xy;
    merge(x.begin(), x.end(), y.begin(), y.end(), back_inserter(xy));
    cout << "xy merge = ";
    for (auto elem : xy)
        cout << elem << " - ";
    cout << endl;

    // Set Algorithms

    make_heap(x.begin(), x.end());

    cout << "x make heap = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    push_heap(x.begin(), x.end());

    cout << "x push heap = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    pop_heap(x.begin(), x.end());

    cout << "x pop heap = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    string s1 = "kangaroo";
    string s2 = "kangaro";
    string s3 = "kangaroa";
    bool b1 = lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
    bool b2 = lexicographical_compare(s1.begin(), s1.end(), s3.begin(), s3.end());
    if (b1)
        cout << "kangaroo is smaller than kangaro" << endl;
    else
        cout << "kangaro is bigger than kangaroo" << endl;
    if (b2)
        cout << "kangaroo is bigger than kangaroa" << endl;
    else
        cout << "kangaroa is smaller than kangaroo" << endl;

    // Min and Max

    x.~array();
    y.~array();
    z.~array();
    xy.~vector();

    return 0;
}