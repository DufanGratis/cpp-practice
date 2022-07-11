#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> x{1, 1, 3, 4, 3};
    forward_list<int> y = x; // copy forward list
    forward_list<int> z;

    cout << "Forward list x size: " << x.max_size() << endl;
    cout << "Forward list y size: " << y.max_size() << endl;
    cout << "Forward list z size: " << z.max_size() << endl;

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

    y.reverse(); // melakukan reverse pada forward list y

    cout << "y itr bgn = ";
    auto elem = y.begin(); // memulai iterasi dari elemen pertama
    while (elem != y.end())
    {
        cout << *elem << " > "; // menampilkan elemen pada forward list y sesuai iterasi
        ++elem;                 // iterasi
    }
    cout << endl;

    y.splice_after(y.begin(), x); // menambahkan elemen pada forward list x ke forward list y setelah elemen y.begin()

    cout << "y splice x = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    y.sort(); // mengurutkan elemen dari terkecil ke terbesar pada forward list y

    cout << "y sort = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    y.unique(); // menghapus elemen yang sama secara berurutan pada forward list y

    cout << "y unique = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    y.push_front(4); // menambahkan elemen yang bernilai 4 ke depan forward list y
    y.remove(1);     // menghapus semua elemen yang bernilai 1 pada forward list y

    cout << "y remove = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    y.erase_after(y.before_begin()); // menghapus elemen setelah before_begin, yaitu elemen begin
    y.resize(5);                     // mengubah ukuran forward list y menjadi 5

    cout << "y resize = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    y.clear(); // menghapus semua elemen pada forward list y

    cout << "y clear = ";
    for (auto elem : y)
        cout << elem << " - ";
    cout << endl;

    x.~forward_list();
    y.~forward_list();
    z.~forward_list();

    return 0;
}