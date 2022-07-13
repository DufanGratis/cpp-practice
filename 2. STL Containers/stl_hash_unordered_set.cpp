#include <iostream>
#include <unordered_set>

using namespace std;

struct Record
{
    string name;
    int val;
};

void record_init(Record &r, string n, int v)
{
    r.name = n;
    r.val = v;
}

size_t hf(const Record &r)
{
    return hash<string>()(r.name) ^ hash<int>()(r.val);
};

bool eq(const Record &r, const Record &r2)
{
    return r.name == r2.name && r.val == r2.val;
};

int main()
{
    unordered_set<Record, decltype(&hf), decltype(&eq)> x{
        10,
        hf,
        eq};
    unordered_set<string> y{"a", "b", "c", "d"};

    auto h = y.hash_function();

    cout << "Unordered set y size: " << y.size() << endl;
    cout << "Unordered set y load factor: " << y.load_factor() << endl;
    cout << "Unordered set y bucket count: " << y.bucket_count() << endl;
    cout << "Unordered set y max load factor: " << y.max_load_factor() << endl;

    cout << "y - hash_function" << endl;
    for (auto str : y)
    {
        cout << str << " - ";
        cout << h(str) << " - ";

        auto e = y.key_eq()(str, "a");
        if (e)
            cout << "Found 'a'" << endl;
        else
            cout << "Not 'a'" << endl;
    }

    auto b = y.bucket_count();

    for (int i = 0; i != b; ++i)
    {
        cout << "Bucket #" << i << " has " << y.bucket_size(i) << " elements" << endl;
    }

    Record r1, r2, r3, r4;
    record_init(r1, "andy", 7);
    record_init(r2, "al", 9);
    record_init(r3, "bill", -3);
    record_init(r4, "barbara", 12);

    x.insert({r1, r2, r3, r4});

    for (auto elem : x)
        cout << "{" << elem.name << ", " << elem.val << "}" << endl;

    x.~unordered_set();
    y.~unordered_set();

    return 0;
}