#include <iostream>
using namespace std;
class Complex
{
    double re, im;

public:
    Complex(double r = 0.0, double i = 0.0);
    double real()
    {
        return re;
    }
    double imag()
    {
        return im;
    }
};

Complex::Complex(double r, double i) : re(r), im(i) {}

int main()
{
    double x = 2.2;
    int i0 = (int)x; // cast a double to an int
    int i1(x);       // initialisation syntax
    int i2 = int(x); // constructor syntax for int
    int i3 = x;      // implicit cast
    Complex c1(x, 0);
    Complex c2 = Complex(x);
    Complex c3 = x;
    cout << x << endl;
    cout << i0 << endl;
    cout << i1 << endl;
    cout << i2 << endl;
    cout << i3 << endl;
    cout << c1.real() << endl;
    cout << c2.real() << endl;
    cout << c3.real() << endl;
}