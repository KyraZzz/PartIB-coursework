#include <iostream>
using namespace std;
class Complex
{
    double re, im; // private by default
public:
    Complex(double r = 0.0, double i = 0.0); // declaration for constructor
    Complex(const Complex &other);           // declaration for copy constructor
    ~Complex(){};                            // default destructor
    double getRe() { return re; }
    double getIm() { return im; }
};

Complex::Complex(double r, double i) : re(r), im(i)
{
    // preferred form, necessary for const fields
    cout << "Normal constructor" << endl;
};
Complex::Complex(const Complex &other)
{
    re = other.re;
    im = other.im;
    cout << "Copy constructor" << endl;
};
/*
Complex::Complex(double r, double i)
{
    re = r, im = i;
    // deprecated initialisation-by-assignment
    // if re or im are const fields, then it is wrong to do assignment
    // C++ make clear distinction between initialisation and assignment,
    // const fields can be initialised, but not assigned
}
*/

int main()
{
    Complex a(1.0, 2.0), b, c(3.0, 4); // stack allocated object, use normal constructor
    Complex d = a;                     // use copy constructor
    d = b;                             // will not call constructors, use assignment operator
    Complex *e = new Complex(1, 5.0);  // heap allocated object, use normal constructor
    return 0;
}
// local object a,b,c are dealloacted on scope exit