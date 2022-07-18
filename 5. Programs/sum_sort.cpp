#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    // input
    string s;

    getline(cin, s);

    istringstream is(s);

    vector<int> v((istream_iterator<int>(is)), istream_iterator<int>());

    // algorithms
    auto elem = v.begin();
    int res = 0;
    int sum = *elem;

    while (elem != v.end())
    {
        ++elem;
        if (*(elem - 1) == *elem)
        {
            sum += *elem;
        }
        else
        {
            res = max(res, sum);
            sum = *elem;
        }
    }

    // output
    cout << res << endl;

    return 0;
}