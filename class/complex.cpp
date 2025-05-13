#include <iostream>
using namespace std;

class Complex
{
private:
    int real, img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex(int x1, int x2)
    {
        real = x1, img = x2;
    }

    Complex operator+(Complex);
    Complex operator*(Complex);
    friend ostream &operator<<(ostream &, Complex &);
    friend istream &operator>>(istream &, Complex &);
};

Complex Complex::operator+(Complex o)
{
    Complex o3;
    o3.real = o.real + real;
    o3.img = o.img + img;
    return o3;
}
Complex Complex::operator*(Complex o)
{
    Complex o2;
    o2.real = real * o.real - img * o.img;
    o2.img = real * o.img + img * o.real;
    return o2;
}

ostream &operator<<(ostream &temp, Complex &c)
{
    temp << "The Complex no. is " << c.real << "+" << c.img << "i\n";
}

istream &operator>>(istream &temp, Complex &c)
{
    cout << "Enter the real part:";
    temp >> c.real;
    cout << "Enter the imaginary part:";
    temp >> c.img;
    return temp;
}

int main(int argc, char *argv[])
{

    Complex x, y(5, 6), sum, m;
    cin >> x;
    cout << x;
    cout << y;
    cout << "After addition" << endl;
    sum = x + y;
    cout << sum;
    cout << "After Multiplication" << endl;
    m = x * y;
    cout << m<<endl;

    return 0;
}