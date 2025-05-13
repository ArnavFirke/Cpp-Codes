#include <iostream>
#include <string>
using namespace std;
template<typename M>
void swapp(M &x,M &y)
{
    M temp=x;
    x=y;
    y=temp;
}
template <class T1, class T2>
class test
{
    T1 a;
    T2 b;

public:
    test(T1 x, T2 y)
    {
        a = x, b = y;
    }
    void show()
    {
        cout << a << " and " << b << endl;
    }
};
template <typename T>

void Array(T arr[], int n)
{
    T sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout<<"Sum is: "<<sum<<endl;
}
int main()
{
    test<float, int> obj1(1.23, 45);
    test<float, float> obj2(1.23, 4.5);
    obj1.show();
    obj2.show();
    int a=10,b=20;
    swapp<int>(a,b);
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Array(arr,n);

    return 0;
}
// add n size arr ele using func template
// class template which sorts n ele
// write memb func of class for exchange of two objs