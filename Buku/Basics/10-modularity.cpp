#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(int s);
    double &operator[](int i);
    int size();

private:
    double *elem;
    int sz;
};

Vector::Vector(int s)
    : elem{new double[s]}, sz{s}
{
}

double &Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}

int main()
{
    int s = 5;
    Vector v(s);
    v[0] = 0.1;
    v[s - 1] = 5.4;
    cout << "vector v has the size of " << v.size() << " with the first vector of " << v[0] << " and last vector of " << v[4] << "\n";

    return 0;
}