#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> x;

    for (int i = 1; i < 6; ++i)
        x.push(i);

    priority_queue<int> y;

    for (int i = 6; i < 9; ++i)
        y.push(i);

    priority_queue<int> z = x; // copy priority queue

    cout << "Priority queue x size: " << x.size() << endl;
    cout << "Priority queue y size: " << y.size() << endl;
    cout << "Priority queue z size: " << z.size() << endl;

    x.swap(y);

    cout << "Priority queue x swap size: " << x.size() << endl;
    cout << "Priority queue y swap size: " << y.size() << endl;
    cout << "Priority queue z size: " << z.size() << endl;

    cout << "Top element of priority queue x is " << x.top() << endl;
    cout << "Top element of priority queue y is " << y.top() << endl;

    cout << "y = ";
    while (!y.empty())
    {
        cout << y.top() << " - ";
        y.pop();
    }
    cout << endl;

    cout << "Priority queue y pop size: " << y.size() << endl;

    x.~priority_queue();
    y.~priority_queue();
    z.~priority_queue();

    return 0;
}