#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> x{1, 1, 3, 4, 3};
    deque<int> y = x; // copy deque
    deque<int> z;

    cout << "Deque x size: " << x.size() << endl;
    cout << "Deque y size: " << y.size() << endl;
    cout << "Deque z size: " << z.size() << endl;

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

    if (!z.empty())
    {
        cout << "z = ";
        for (auto elem : z)
            cout << elem << " - ";
        cout << endl;
    }

    cout << "y itr for = " << y.front() << " + "; // menampilkan elemen pertama pada deque y
    for (int i = 1; i < y.size() - 1; ++i)
        cout << y[i] << " + "; // menampilkan elemen ke-i pada deque y (bisa juga dengan y.at(i))
    cout << y.back() << endl;  // menampilkan elemen terakhir pada deque y

    z.assign({1, 2, 3, 4, 5});

    cout << "z itr bgn = ";
    auto elem = z.begin(); // memulai iterasi dari elemen pertama
    while (elem != z.end())
    {
        cout << *elem << " o "; // menampilkan elemen pada deque z sesuai iterasi
        ++elem;                 // iterasi
    }
    cout << endl;

    y.swap(z); // menukar semua elemen pada deque y dengan semua elemen pada deque z

    z.pop_front(); // menghapus elemen pertama deque z

    z.push_front(2); // memasukkan elemen bernilai 2 menjadi elemen pertama deque z

    z.insert(z.begin() + 1, {6, 9}); // memasukkan elemen bernilai 6 dan 9 ke deque z dimulai dari posisi z.begin() + 1

    y.insert(y.end() - 1, 2, 9);
    ; // memasukkan elemen bernilai 2 dan 9 ke deque y dimulai dari posisi y.end() - 1

    cout << "y insert = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    cout << "z insert = ";
    for (auto elem : z)
        cout << elem << " o ";
    cout << endl;

    y.pop_back(); // menghapus elemen terakhir deque y

    y.push_back(1); // memasukkan elemen bernilai 1 menjadi elemen terakhir deque y

    z.emplace_back(7); // memasukkan elemen bernilai 7 menjadi elemen terakhir deque z

    z.emplace_front(7); // memasukkan elemen bernilai 7 menjadi elemen pertama deque z

    y.emplace(y.begin() + y.size(), 7); // memasukkan elemen bernilai 7 menjadi elemen terakhir deque y

    cout << "y emplace = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    cout << "z emplace = ";
    for (auto elem : z)
        cout << elem << " o ";
    cout << endl;

    auto a = y.erase(y.begin());   // menghapus elemen pertama dari deque y
    auto b = z.erase(z.end() - 1); // menghapus elemen terakhir dari dequez z (bisa juga dengan z.rbegin())

    if (a == y.begin())
        cout << "a is the first element of y" << endl;
    if (b == z.end())
        cout << "b is the last element of z" << endl;

    y.resize(5); // mengubah ukuran deque y menjadi 5

    z.resize(11, 0); // mengubah ukuran deque z menjadi 11 yang diisi dengan elemen bernilai 0 pada elemen yang tumbuh

    cout << "y resize = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    cout << "z resize = ";
    for (auto elem : z)
        cout << elem << " o ";
    cout << endl;

    y.clear(); // menghapus semua elemen pada deque y

    cout << "y clear = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    x.~deque();
    y.~deque();
    z.~deque();

    return 0;
}