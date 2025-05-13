#include<iostream>
#include<string>
using namespace std;
typedef void (*ptr)();
void display(){
    cout<<"Using func pointer"<<endl;
}
int main()
{
    ptr p;
    p=&display;
    p();
    cout<<p<<endl;
    return 0;
} 