#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, char, greater<int>> x{{1, 'a'}, {1, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}}; // harus unik
    multimap<int, char> mx{{1, 'a'}, {1, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    map<int, char, greater<int>> y;
    map<int, char> z{{5, 'F'}, {7, 'G'}, {1, 'A'}, {4, 'D'}, {5, 'E'}, {2, 'B'}}; // harus unik dengan sort less<int> secara default

    cout << "Map x size: " << x.size() << endl;
    cout << "Map y size: " << y.size() << endl;
    cout << "Map z size: " << z.size() << endl;

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

    map<int, char, greater<int>> a = x;
    // map<int, int, greater<int>> b = x; tidak bisa karena x berupa pair int dan char sementar b berupa pair int dan int
    y = x; // harus sama menggunakan greater<int> juga untuk copy map sesuai dengan map yang dicopy
    // z = x; tidak bisa karena z menggunakan less<int> dan x menggunakan greater<int>

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

    cout << "Total elements with the key of 1 in multimap mx is " << mx.count(1) << endl;

    auto search = mx.find(1);
    if (search != mx.end())
        cout << "The first element with the key of " << (*search).first << " in multimap mx is found with the value of " << (*search).second << endl;
    else
        cout << "Multimap mx does not have element with the key of 1" << endl;

    auto lower = mx.lower_bound(2); // memberikan iterasi elemen pertama dengan key yang tidak lebih kecil dari 2
    auto upper = mx.upper_bound(3); // memberikan iterasi elemen pertama dengan key yang lebih besar dari 3

    cout << "mx lower = ";
    while (lower != mx.end())
    {
        cout << (*lower).first << "->" << (*lower).second << " - ";
        ++lower; // iterasi
    }
    cout << endl;

    cout << "mx upper = ";
    while (upper != mx.end())
    {
        cout << (*upper).first << "->" << (*upper).second << " - ";
        ++upper; // iterasi
    }
    cout << endl;

    auto range = mx.equal_range(1); // memberikan range elemen dengan key yang bernilai 1

    cout << "mx range 1 = ";
    for (auto itr_r = range.first; itr_r != range.second; ++itr_r)
        cout << (*itr_r).first << "->" << (*itr_r).second << " - ";
    cout << endl;

    a.insert({2, 'b'}); // menambahkan elemen bernilai {2, 'b'} ke map a dan auto sort sesuai yang digunakan

    y.swap(a); // menukar map y dengan map a (bisa juga dengan swap(y,a))

    auto key_a = a.key_comp();     // key_a sebagai nilai key dari map a
    auto value_y = y.value_comp(); // value_y sebagai nilai value dari map y

    cout << "a swap  = ";
    for (auto elem : a)
    {
        if (key_a(4, elem.first))
            cout << "|";
        cout << elem.first << "->" << elem.second << " o ";
    }
    cout << endl;

    cout << "y swap = ";
    for (auto elem : y)
    {
        if (value_y(elem, {3, 'c'}))
            cout << "!";
        cout << elem.first << "->" << elem.second << " - ";
    }
    cout << endl;

    // memasukkan elemen {2, 'b'}, {8, 'h'}, dan {6, 'f'} pada map a dan auto sort
    auto iter = a.emplace(2, 'b'); // menyimpan posisi elemen bernilai 2 pada map a
    a.emplace(8, 'h');
    a.emplace(6, 'f');

    a.emplace_hint(iter.first, 0, '*'); // memasukkan elemen bernilai 7 pada map a dimulai dari iter.first, yaitu posisi elemen bernilai 2 agar lebih cepat dibandingkan dengan dimulai dari posisi elemen berniali 8

    y.insert({{7, 'g'}, {0, '*'}, {9, 'i'}}); // memasukkan elemen {7, 'g'}, {0, '*'}, dan {9, 'i'} pada map y dan auto sort

    cout << "a rbgn = ";
    auto relem = a.rbegin(); // memulai iterasi dari elemen terakhir
    while (relem != a.rend())
    {
        cout << (*relem).first << "->" << (*relem).second << " o ";
        ++relem; // iterasi
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

    auto remove_1 = y.erase(1);       // menghapus elemen dengan key bernilai 1 pada map y dan return banyak elemen yang dihapus
    auto elem_a = a.erase(a.begin()); // menghapus elemen pertama pada map a dan return posisi mapelahnya

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

    y.clear(); // menghapus semua elemen pada map y

    cout << "y clear = ";
    for (auto elem : y)
        cout << elem.first << "->" << elem.second << " - ";
    cout << endl;

    x.~map();
    y.~map();
    z.~map();
    a.~map();

    return 0;
}