#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> x{1, 2, 3, 4, 5};
    vector<int> y = x; // copy vector
    vector<int> z;

    cout << "Vector x size: " << x.size() << endl;
    cout << "Vector y size: " << y.size() << endl;
    cout << "Vector z size: " << z.size() << endl;

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

    z.assign(4, 6); // mengubah elemen pada vektor z menjadi elemen 6 sebanyak 2 kali

    if (!z.empty())
    {
        cout << "z assign = ";
        for (auto elem : z)
            cout << elem << " - ";
        cout << endl;
    }

    if (z == y) // semua elemen pada vector z sama dengan semua vector pada vector y
    {
        cout << "vector z is the same with vector y" << endl;
    }
    else // semua elemen pada vector z tidak sama dengan semua elemen pada vector y
    {
        cout << "vector z is not the same with vector y where ";
        if (z > y) // semua elemen pada vector z lebih besar dari semua elemen pada vector y
        {
            cout << "vector z is bigger than vector y" << endl;
        }
        else // semua elemen pada vector z lebih kecil dari semua elemen pada vector y
        {
            cout << "vector z is smaller than vector y" << endl;
        }
    }

    z.swap(x); // semua elemen pada vector x ditukar dengan semua elemen pada vector z (bisa juga dengan swap(x, z))

    x.resize(3); // mengubah ukuran vector x dari 4 menjadi 3

    cout << "x swap = ";
    for (auto elem : x)
        cout << elem << " - ";
    cout << endl;

    cout << "z swap = ";
    for (auto elem : z)
        cout << elem << " - ";
    cout << endl;

    z.push_back(-2); // menambahkan elemen -2 ke belakang vector z

    cout << "z itr for = " << z.front() << " + "; // menampilkan elemen pertama pada vector z
    for (int i = 1; i < z.size() - 1; ++i)
        cout << z[i] << " + "; // menampilkan elemen ke-i pada vector z (bisa juga dengan z.at(i))
    cout << z.back() << endl;  // menampilkan elemen terakhir pada vector z

    z.pop_back(); // mengeluarkan elemen terakhir dari vector z tanpa return nilai elemen tersebut

    z.erase(z.begin()); // menghapus elemen pertama dari vector z

    cout << "z itr bgn = ";
    auto elem = z.begin(); // memulai iterasi dari elemen pertama
    while (elem != z.end())
    {
        cout << *elem << " < "; // menampilkan elemen pada vector z sesuai iterasi
        ++elem;                 // iterasi
    }
    cout << endl;

    z.insert(z.end(), 3, 6);

    cout << "z itr rbgn = ";
    auto relem = z.rbegin(); // memulai iterasi terbalik dari elemen pertama
    while (relem != z.rend())
    {
        cout << *relem << " > "; // menampilkan elemen pada vector z sesuai iterasi
        ++relem;                 // iterasi
    }
    cout << endl;

    z.emplace(z.begin() + 3, 9);
    z.emplace_back(8);

    cout << "z emp = ";
    for (auto elem : z)
        cout << elem << " - ";
    cout << endl;

    z.clear();

    cout << "Vector z size after cleared is " << z.size() << endl;

    x.~vector();
    y.~vector();
    z.~vector();

    return 0;
}