#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, char> x{{1, 'a'}, {1, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}}; // harus unik
    unordered_multimap<int, char> mx{{1, 'a'}, {1, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    unordered_map<int, char> y;
    unordered_map<int, char> z{{5, 'F'}, {7, 'G'}, {1, 'A'}, {4, 'D'}, {5, 'E'}, {2, 'B'}}; // harus unik dengan sort less<int> secara default

    cout << "Unordered map x size: " << x.size() << endl;
    cout << "Unordered map y size: " << y.size() << endl;
    cout << "Unordered map z size: " << z.size() << endl;

    if (!x.empty())
    {
        cout << "x = ";
        for (auto elem : x)
            cout << elem.first << "->" << elem.second << " - ";
        cout << endl;
    }

    if (!y.empty())
    {
        cout << "y = ";
        for (auto elem : y)
            cout << elem.first << "->" << elem.second << " - ";
        cout << endl;
    }

    if (!z.empty())
    {
        cout << "z = ";
        for (auto elem : z)
            cout << elem.first << "->" << elem.second << " - ";
        cout << endl;
    }

    unordered_map<int, char> a = x;
    // unordered map<int, int> b = x; tidak bisa karena x berupa pair int dan char sementar b berupa pair int dan int
    y = x; // copy unordered map

    if (!a.empty())
    {
        cout << "a = ";
        for (auto elem : a)
            cout << elem.first << "->" << elem.second << " o ";
        cout << endl;
    }

    if (!y.empty())
    {
        cout << "y = ";
        for (auto elem : y)
            cout << elem.first << "->" << elem.second << " - ";
        cout << endl;
    }

    if (!mx.empty())
    {
        cout << "mx = ";
        for (auto elem : mx)
            cout << elem.first << "->" << elem.second << " - ";
        cout << endl;
    }

    cout << "Total elements with the key of 1 in multiunordered map mx is " << mx.count(1) << endl;

    auto search = mx.find(1);
    if (search != mx.end())
        cout << "The first element with the key of " << (*search).first << " in multiunordered map mx is found with the value of " << (*search).second << endl;
    else
        cout << "Multiunordered map mx does not have element with the key of 1" << endl;

    auto range = mx.equal_range(1); // memberikan range elemen dengan key yang bernilai 1

    cout << "mx range 1 = ";
    for (auto itr_r = range.first; itr_r != range.second; ++itr_r)
        cout << (*itr_r).first << "->" << (*itr_r).second << " - ";
    cout << endl;

    a.insert({2, 'b'}); // menambahkan elemen bernilai {2, 'b'} ke unordered map a dan auto sort sesuai yang digunakan

    y.swap(a); // menukar unordered map y dengan unordered map a (bisa juga dengan swap(y,a))

    // memasukkan elemen {2, 'b'}, {8, 'h'}, dan {6, 'f'} pada unordered map a dan auto sort
    a.emplace(2, 'b');
    a.emplace(8, 'h');
    auto iter = a.emplace(6, 'f'); // menyimpan posisi elemen bernilai 6 pada unordered map a

    a.emplace_hint(iter.first, 0, '*'); // memasukkan elemen bernilai 0 pada unordered map a dimulai dari iter.first, yaitu posisi elemen bernilai 6

    y.insert({{7, 'g'}, {0, '*'}, {9, 'i'}}); // memasukkan elemen {7, 'g'}, {0, '*'}, dan {9, 'i'} pada unordered map y dan auto sort

    cout << "a bgn = ";
    auto elem1 = a.begin(); // memulai iterasi dari elemen terakhir
    while (elem1 != a.end())
    {
        cout << (*elem1).first << "->" << (*elem1).second << " o ";
        ++elem1; // iterasi
    }
    cout << endl;

    cout << "y bgn = ";
    auto elem = y.begin(); // memulai iterasi dari elemen pertama
    while (elem != y.end())
    {
        cout << (*elem).first << "->" << (*elem).second << " - ";
        ++elem; // iterasi
    }
    cout << endl;

    auto remove_1 = y.erase(1);       // menghapus elemen dengan key bernilai 1 pada unordered map y dan return banyak elemen yang dihapus
    auto elem_a = a.erase(a.begin()); // menghapus elemen pertama pada unordered map a dan return posisi unordered mapelahnya

    cout << "a erase = ";
    while (elem_a != a.end())
    {
        cout << (*elem_a).first << "->" << (*elem_a).second << " o ";
        ++elem_a; // iterasi
    }
    cout << endl;

    cout << "y erase = ";
    for (auto elem : y)
        cout << elem.first << "->" << elem.second << " - ";
    cout << endl;

    cout << "Total of elements with the key value of 1 deleted is " << remove_1 << endl;

    y.clear(); // menghapus semua elemen pada unordered map y

    cout << "y clear = ";
    for (auto elem : y)
        cout << elem.first << "->" << elem.second << " - ";
    cout << endl;

    x.~unordered_map();
    mx.~unordered_multimap();
    y.~unordered_map();
    z.~unordered_map();
    a.~unordered_map();

    return 0;
}