#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int main()
{
    array<int, 5> x{6, 7, 8, 9, 1};
    array<int, 5> y{1, 2, 3, 4, 5};

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

    array<int, 5> z{1, 2, 3, 2, 1};

    cout << "z = ";
    for (auto elem : z)
        cout << elem << " x ";
    cout << endl;
    auto eq = equal(z.begin(), z.begin() + z.size() / 2, z.rbegin());
    cout << "Array z is" << ((eq) ? " " : " not ") << "a palindrome" << endl;

    string m1 = "abcdba";
    string m2 = "abcdea";
    auto mm = mismatch(m1.begin(), m1.end(), m2.begin());
    cout << "The same elements of " << m1 << " and " << m2 << " are ";
    for (auto m = m1.begin(); m != mm.first; ++m)
        cout << *m;
    cout << " and stops at " << *mm.first << " on abcdba and " << *mm.second << " on abcdea" << endl;

    string n1 = "abcdba";
    string n2 = "abce";
    auto ns = search(n1.begin(), n1.end(), n2.begin(), n2.end());
    cout << n1 << ((ns != n1.end()) ? " does" : " does not") << " contains the string " << n2 << endl;

    // Modifying

    vector<int> p{1, 2, 3, 2, 2, 1};
    vector<int> q;

    copy(p.begin(), p.end(), back_inserter(q));
    cout << "p = ";
    for (auto elem : p)
        cout << elem << " - ";
    cout << endl;

    cout << "q = ";
    for (auto elem : q)
        cout << elem << " - ";
    cout << endl;

    auto un = unique(q.begin(), q.end());
    q.erase(un, q.end());

    cout << "q unique = ";
    for (auto q_itr = q.begin(); q_itr != q.end(); ++q_itr)
        cout << *q_itr << " - ";
    cout << endl;

    remove(q.begin(), q.end(), 3);
    replace(q.begin(), q.end(), 1, -1);

    cout << "q replace = ";
    for (auto q_itr = q.begin(); q_itr != q.end(); ++q_itr)
        cout << *q_itr << " - ";
    cout << endl;

    sort(p.begin(), p.end());
    cout << "p sort = ";
    for (auto elem : p)
        cout << elem << " - ";
    cout << endl;

    rotate(p.begin(), p.begin() + 1, p.end());
    cout << "p rotate left = ";
    for (auto elem : p)
        cout << elem << " - ";
    cout << endl;

    random_shuffle(p.begin(), p.end());
    cout << "p random = ";
    for (auto elem : p)
        cout << elem << " - ";
    cout << endl;

    auto even = partition(p.begin(), p.end(), [](int pp)
                          { return pp % 2 == 0; });
    cout << "p even = ";
    for (auto p_even = p.begin(); p_even != even; ++p_even)
        cout << *p_even << " - ";
    cout << endl;

    cout << "p odd = ";
    for (auto p_odd = even; p_odd != p.end(); ++p_odd)
        cout << *p_odd << " - ";
    cout << endl;

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

    cout << "The max element of x is " << *max_element(x.begin(), x.end()) << " and the min element of x is " << *min_element(x.begin(), x.end()) << endl;

    x.~array();
    y.~array();
    z.~array();
    xy.~vector();

    return 0;
}