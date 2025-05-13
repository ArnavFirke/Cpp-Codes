#include <iostream>
using namespace std;

class Base
{
protected:
    int data1;
    int data2;

public:
    void setData();
};

void Base ::setData(void)
{
    data1 = 10;
    data2 = 20;
}

class Derived : public Base
{

    int data3;
public:
    void setd3();
    void display();
};

void Derived ::setd3()
{
    data3 = data2 * data1;
}

void Derived ::display()
{
    cout << "Value of data 1 is " << data1 << endl;
    cout << "Value of data 2 is " << data2 << endl;
    cout << "Value of data 3 is " << data3 << endl;
}
int main()
{
    Derived data;
    Base *b;
    b=&data;
    b->setData();
    data.setd3();
    data.display();
    // data.data3=404;
    data.display();
    return 0;
}
