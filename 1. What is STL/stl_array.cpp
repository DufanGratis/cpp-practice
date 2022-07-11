#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5> x{1, 2, 3, 4, 5};
    array<int, 5> y = x; // ukuran array harus sama untuk copy array

    cout << "Array x size: " << x.size() << endl;
    cout << "Array y size: " << y.size() << endl;

    if (!x.empty())
    {
        cout << "x = ";
        for (auto elem : x)
            cout << elem << " - ";
        cout << endl;
    }

    if (!y.empty())
    {
        cout << "y = ";
        for (auto elem : y)
            cout << elem << " - ";
        cout << endl;
    }

    if (x == y) // semua elemen pada array x sama dengan semua array pada array y
    {
        cout << "Array x is the same with array y" << endl;
    }
    else // semua elemen pada array x tidak sama dengan semua elemen pada array y
    {
        cout << "Array x is not the same with array y where ";
        if (x > y) // semua elemen pada array x lebih besar dari semua elemen pada array y
        {
            cout << "array x is bigger than array y" << endl;
        }
        else // semua elemen pada array x lebih kecil dari semua elemen pada array y
        {
            cout << "array x is smaller than array y" << endl;
        }
    }

    y.fill(0); // semua elemen pada array y menjadi angka 0

    cout << "y fill = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    x.swap(y); // semua elemen pada array x ditukar dengan semua elemen pada array y (bisa juga dengan swap(x, y))

    cout << "x swap = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    cout << "y swap = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    cout << "y itr for = " << y.front() << " + "; // menampilkan elemen pertama pada array y
    for (int i = 1; i < y.size() - 1; ++i)
        cout << y[i] << " + "; // menampilkan elemen ke-i pada array y (bisa juga dengan y.at(i))
    cout << y.back() << endl;  // menampilkan elemen terakhir pada array y

    cout << "y itr bgn = ";
    auto elem = y.begin(); // memulai iterasi dari elemen pertama
    while (elem != y.end())
    {
        cout << *elem << " < "; // menampilkan elemen pada array y sesuai iterasi
        ++elem;                 // iterasi
    }
    cout << endl;

    cout << "y itr rbgn = ";
    auto relem = y.rbegin(); // memulai iterasi terbalik dari elemen pertama
    while (relem != y.rend())
    {
        cout << *relem << " > "; // menampilkan elemen pada array y sesuai iterasi
        ++relem;                 // iterasi
    }
    cout << endl;

    return 0;
}