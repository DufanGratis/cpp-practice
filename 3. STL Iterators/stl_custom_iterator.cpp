#include <iostream>
#include <iterator>

using namespace std;

class Integers
{
public:
    Integers(int s)
    {
        m_data = new int[s];
        sz = s;
    };
    struct Iterator
    {
        using difference_type = ptrdiff_t;
        using value_type = int;
        using pointer = int *;
        using reference = int &;
        using iterator_category = forward_iterator_tag;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const
        {
            return *m_ptr;
        }
        pointer operator->()
        {
            return m_ptr;
        }
        Iterator &operator++()
        {
            m_ptr++;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator &a, const Iterator &b)
        {
            return a.m_ptr == b.m_ptr;
        };
        friend bool operator!=(const Iterator &a, const Iterator &b)
        {
            return a.m_ptr != b.m_ptr;
        };

    private:
        pointer m_ptr;
    };

    Iterator begin()
    {
        return Iterator(&m_data[0]);
    }
    Iterator middle()
    {
        return Iterator(&m_data[sz / 2]);
    }
    Iterator end()
    {
        return Iterator(&m_data[sz]);
    }
    Iterator size()
    {
        return &sz;
    }

private:
    int *m_data;
    int sz;
};

int main()
{
    Integers x(10);
    fill(x.begin(), x.middle(), 5);
    fill(x.middle(), x.end(), -5);

    int i = 1;
    for (auto elem : x)
    {
        cout << i << ": " << elem << endl;
        ++i;
    }
    return 0;
}