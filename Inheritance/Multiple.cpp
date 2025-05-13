#include<iostream>
using namespace std;

class Base1{
protected:
    int base1;

public:
    void set_base1(int a)
    {
        base1 = a;
    }
};

class Base2{
protected:
    int base2;

public:
    void set_base2(int a)
    {
        base2 = a;
    }
};

class Base3{
protected:
    int base3;

public:
    void set_base3(int a)
    {
        base3 = a;
    }
};
class Derived : public Base1, public Base2, public Base3
{
    public: 
        void show(){
            cout << "The value of Base1 is " << base1<<endl;
            cout << "The value of Base2 is " << base2<<endl;
            cout << "The value of Base3 is " << base3<<endl;
            cout << "The sum of these values is " << base1 + base2 + base3 << endl;
        }
};
int main()
{
    Derived obj;
    obj.set_base1(25);
    obj.set_base2(5);
    obj.set_base3(15);
    obj.show();
    
    return 0;
}
