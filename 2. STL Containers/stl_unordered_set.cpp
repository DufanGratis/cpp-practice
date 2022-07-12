#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> x{1, 1, 3, 4, 5}; // harus unik
    unordered_multiset<int> mx{1, 1, 3, 4, 5};
    unordered_set<int> y;
    unordered_set<int> z{5, 7, 1, 4, 5, 2}; // harus unik dengan sort less<int> secara default

    cout << "Unordered set x size: " << x.size() << endl;
    cout << "Unordered set y size: " << y.size() << endl;
    cout << "Unordered set z size: " << z.size() << endl;

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

    unordered_set<int> a = x;
    y = x; // copy unordered set

    if (!y.empty())
    {
        cout << "y = ";
        for (auto elem : y)
            cout << elem << " - ";
        cout << endl;
    }

    if (!mx.empty())
    {
        cout << "mx = ";
        for (auto elem : mx)
            cout << elem << " - ";
        cout << endl;
    }

    cout << "Total elements with the key of 1 in unordered multiset mx is " << mx.count(1) << endl;

    auto search = mx.find(1);
    if (search != mx.end())
        cout << "The element 1 in unordered multiset mx is found" << endl;
    else
        cout << "Unordered multiset mx does not have element 1" << endl;

    auto range = mx.equal_range(1); // memberikan range elemen dengan key yang bernilai 1

    cout << "mx range 1 = ";
    for (auto itr_r = range.first; itr_r != range.second; ++itr_r)
        cout << *itr_r << " - ";
    cout << endl;

    a.insert(2); // menambahkan elemen bernilai 2 ke unordered set a dan auto sort sesuai yang digunakan

    y.swap(a); // menukar unordered set y dengan unordered set a (bisa juga dengan swap(y,a))

    y.insert({7, 0, 9}); // memasukkan elemen 7, 0, dan 9 pada unordered set y dan auto sort
    // memasukkan elemen 2, 8, dan 6 pada unordered set a dan auto sort
    auto iter = a.emplace(2); // menyimpan posisi elemen bernilai 2 pada unordered set a
    a.emplace(8);
    a.emplace(6);

    a.emplace_hint(iter.first, 0); // memasukkan elemen bernilai 0 pada unordered set a dimulai dari iter.first, yaitu posisi elemen bernilai 2

    cout << "y bgn = ";
    auto elem = y.begin(); // memulai iterasi dari elemen pertama
    while (elem != y.end())
    {
        cout << *elem << " - "; // menampilkan elemen pada unordered set sesuai iterasi
        ++elem;                 // iterasi
    }
    cout << endl;

    cout << "a bgn = ";
    auto elem2 = a.begin(); // memulai iterasi dari elemen terakhir
    while (elem2 != a.end())
    {
        cout << *elem2 << " o "; // menampilkan elemen pada unordered set sesuai iterasi
        ++elem2;                 // iterasi
    }
    cout << endl;

    auto remove_1 = mx.erase(1);      // menghapus elemen bernilai 1 pada unordered set y dan return banyak elemen yang dihapus
    auto elem_a = a.erase(a.begin()); // menghapus elemen pertama pada unordered set a dan return posisi unordered setelahnya

    cout << "mx erase = ";
    for (auto elem : mx)
        cout << elem << " - ";
    cout << endl;

    cout << "Total of element 1 deleted is " << remove_1 << endl;

    cout << "a erase = ";
    while (elem_a != a.end())
    {
        cout << *elem_a << " o "; // menampilkan elemen pada unordered set sesuai iterasi
        ++elem_a;                 // iterasi
    }
    cout << endl;

    y.clear(); // menghapus semua elemen pada unordered set y

    cout << "y clear = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    x.~unordered_set();
    mx.~unordered_multiset();
    y.~unordered_set();
    z.~unordered_set();
    a.~unordered_set();

    return 0;
}