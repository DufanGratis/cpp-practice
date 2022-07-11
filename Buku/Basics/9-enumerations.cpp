#include <iostream>
using namespace std;

enum class Color
{
    red,
    blue,
    green
};

enum class Traffic_light
{
    green,
    yellow,
    red
};

Traffic_light &operator++(Traffic_light &t)
{
    switch (t)
    {
    case Traffic_light::green:
        return t = Traffic_light::yellow;
    case Traffic_light::yellow:
        return t = Traffic_light::red;
    case Traffic_light::red:
        return t = Traffic_light::green;
    }
}

int main()
{
    // Color x = red;
    // Color y = Traffic_light::red;
    Color col = Color::red;
    Traffic_light light = Traffic_light::red;
    // int i = Color::red;
    // Color c = 2;
    Traffic_light next = ++light;

    return 0;
}