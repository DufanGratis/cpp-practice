#include <iostream>
using namespace std;

struct Vector
{
    int sz;
    double *elem;
};

void vector_init(Vector &v, int s)
{
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s)
{
    Vector v;
    vector_init(v, s);
    for (int i = 0; i != s; ++i)
        cin >> v.elem[i];

    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i];
    return sum;
}

int main()
{
    int s = 5;
    double sum = read_and_sum(s);
    cout << "sum of " << s << " amount of vectors is " << sum << "\n";

    return 0;
}