#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // input
    int n;
    int x;
    int y;
    vector<pair<int, int>> v;

    cin >> n;

    for (int i = 0; i != n; ++i)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    // algorithm
    array<array<char, 10>, 10> ms_map;

    for (int m = 0; m != n; ++m)
    {
        ms_map[v[m].first][v[m].second] = 'x';
    }

    for (int i = 0; i != 10; ++i)
    {
        for (int j = 0; j != 10; ++j)
        {
            if (ms_map[i][j] != 'x')
            {
                int mines = 0;
                if (ms_map[i - 1][j] == 'x')
                    mines += 1;
                if (ms_map[i - 1][j - 1] == 'x')
                    mines += 1;
                if (ms_map[i - 1][j + 1] == 'x')
                    mines += 1;
                if (ms_map[i][j - 1] == 'x')
                    mines += 1;
                if (ms_map[i][j + 1] == 'x')
                    mines += 1;
                if (ms_map[i + 1][j - 1] == 'x')
                    mines += 1;
                if (ms_map[i + 1][j] == 'x')
                    mines += 1;
                if (ms_map[i + 1][j + 1] == 'x')
                    mines += 1;
                if (mines > 0)
                    ms_map[i][j] = '0' + mines;
                else
                    ms_map[i][j] = '.';
            }
        }
    }

    // output
    for (int i = 0; i != 10; ++i)
    {
        for (int j = 0; j != 10; ++j)
        {
            cout << ms_map[i][j];
        }
        cout << endl;
    }

    return 0;
}