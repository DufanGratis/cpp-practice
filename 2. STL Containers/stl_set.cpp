#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int, greater<int>> x{1, 1, 3, 4, 5}; // harus unik
    multiset<int> mx{1, 1, 3, 4, 5};
    set<int, greater<int>> y;
    set<int> z{5, 7, 1, 4, 5, 2}; // harus unik dengan sort less<int> secara default

    cout << "Set x size: " << x.size() << endl;
    cout << "Set y size: " << y.size() << endl;
    cout << "Set z size: " << z.size() << endl;

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

    set<int, greater<int>> a = x;
    y = x; // harus sama menggunakan greater<int> juga untuk copy set sesuai dengan set yang dicopy
    // z = x; tidak bisa karena z menggunakan less<int> dan x menggunakan greater<int>

    if (!y.empty())
    {
        cout << "y = ";
        for (auto elem : y)
            cout << elem << " - ";
        cout << endl;
    }

    a.insert(2); // menambahkan elemen bernilai 2 ke set a dan auto sort sesuai yang digunakan

    y.swap(a); // menukar set y dengan set a (bisa juga dengan swap(y,a))

    auto key_a = a.key_comp();     // key_a sebagai nilai key dari set a
    auto value_y = y.value_comp(); // value_y sebagai nilai value dari set y
    // khusus untuk set, key dan value bernilai sama

    cout << "y swap = ";
    for (auto elem : y)
    {
        if (value_y(elem, 3))
            cout << "!";
        cout << elem << " - ";
    }
    cout << endl;

    cout << "a swap  = ";
    for (auto elem : a)
    {
        if (key_a(3, elem))
            cout << "|";
        cout << elem << " o ";
    }
    cout << endl;

    y.insert({7, 0, 9}); // memasukkan elemen 7, 0, dan 9 pada set y dan auto sort
    // memasukkan elemen 2, 8, dan 6 pada set a dan auto sort
    auto iter = a.emplace(2); // menyimpan posisi elemen bernilai 2 pada set a
    a.emplace(8);
    a.emplace(6);

    a.emplace_hint(iter.first, 0); // memasukkan elemen bernilai 7 pada set a dimulai dari iter.first, yaitu posisi elemen bernilai 2 agar lebih cepat dibandingkan dengan dimulai dari posisi elemen berniali 8

    cout << "y bgn = ";
    auto elem = y.begin(); // memulai iterasi dari elemen pertama
    while (elem != y.end())
    {
        cout << *elem << " - "; // menampilkan elemen pada set sesuai iterasi
        ++elem;                 // iterasi
    }
    cout << endl;

    cout << "a rbgn = ";
    auto relem = a.rbegin(); // memulai iterasi dari elemen terakhir
    while (relem != a.rend())
    {
        cout << *relem << " o "; // menampilkan elemen pada set sesuai iterasi
        ++relem;                 // iterasi
    }
    cout << endl;

    auto remove_1 = mx.erase(1);      // menghapus elemen bernilai 1 pada set y dan return banyak elemen yang dihapus
    auto elem_a = a.erase(a.begin()); // menghapus elemen pertama pada set a dan return posisi setelahnya

    cout << "mx erase = ";
    for (auto elem : mx)
        cout << elem << " - ";
    cout << endl;

    cout << "Total of element 1 deleted is " << remove_1 << endl;

    cout << "a erase = ";
    while (elem_a != a.end())
    {
        cout << *elem_a << " o "; // menampilkan elemen pada set sesuai iterasi
        ++elem_a;                 // iterasi
    }
    cout << endl;

    y.clear(); // menghapus semua elemen pada set y

    cout << "y clear = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    x.~set();
    mx.~set();
    y.~set();
    z.~set();
    a.~set();

    return 0;
}