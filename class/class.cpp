#include <iostream>
using namespace std;
class Employee
{
private:
    int id;
    static int count;

public:
    void setdata();
    void show()
    {
        cout << "Id of employee is " << id << endl;
    }
    static void getcount() // to use static data members
    {
        cout << "The employee number is " << count << endl;
    }
};
int Employee::count; // int Employee:: count=100; possible

void Employee ::setdata()
{
    cout << "Enter the Id :";
    cin >> id;
    count++;
}
int main()
{
    Employee arnav, a, b;
    arnav.setdata();
    // arnav.id=500; error as private var
    arnav.show();
    Employee::getcount();

    a.setdata();
    a.show();
    Employee::getcount();

    b.setdata();
    b.show();
    Employee::getcount();
    return 0;
}

