#include <iostream>

namespace My_code
{
    class complex
    {
    public:
        complex(double r, double i);
        double real();
        double imag();

    private:
        double re;
        double im;
    };

    complex::complex(double r, double i)
        : re{r}, im{i}
    {
    }

    double complex::real()
    {
        return re;
    }

    double complex::imag()
    {
        return im;
    }

    int main();
}

int My_code::main()
{
    complex z(1.0, 2.0);
    std::cout << '{' << z.real() << ',' << z.imag() << "}\n";
};

int main()
{
    return My_code::main();

    return 0;
}