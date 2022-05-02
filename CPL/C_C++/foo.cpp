class A
{
};
class B : public A
{
};
A **p;
B **q;

void foo()
{
    *p = *q;
}

void foo2()
{
    // p = q;
}

int main()
{
    A *a = new A();
    A **p = &a;
    B *b = new B();
    B **q = &b;
    *p = new A;
    return 0;
}