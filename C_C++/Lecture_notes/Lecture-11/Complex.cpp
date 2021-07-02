#include <stdio.h>
class Complex
{
    double re, im; // private by default
public:
    Complex(double r = 1.0, double i = 1.0); // declaration for constructor
    int getReal();
    int getIm();
    void setReal(double r)
    {
        re = r;
    }
    void setIm(double i)
    {
        im = i;
    }
};

Complex::Complex(double r, double i) : re(r), im(i)
{
    // preferred form, necessary for const fields
}

int Complex::getReal()
{
    return re;
}

int Complex::getIm()
{
    return im;
}

int main()
{
    Complex c(2.0), d(), e(1, 5.0); // stack allocated object
    Complex x;
    printf("variable %s has real %d and imaginary %d\n", "x", x.getReal(), x.getIm());
    Complex y = x;
    printf("variable %s has real %d and imaginary %d\n", "y", y.getReal(), y.getIm());
    y.setIm(3.0);
    x = y;
    printf("variable %s has real %d and imaginary %d\n", "x", x.getReal(), x.getIm());
    return 0;
}