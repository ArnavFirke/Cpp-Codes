#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
class details
{
private:
    string name;
    int age;

public:
    void set_details()
    {
        cin >> name >> age;
    }
    string na() { return name; }
    int ag() { return age; }
};
int main()
{
    details d[10];
    fstream f;
    f.open("data.txt", ios ::out);
    for (int i = 0; i < 2; i++)
    {
        d[i].set_details();
        // f << d[i].na() << ' ' << d[i].ag() << endl;
        f.put(d[i].ag());
        // f.put(d[i].na());
    }
    f.close();

    char n;
    int a;
    f.open("data.txt", ios::in);
    for (int i = 0; i < 2; i++)
    {
        // f >> n >> a;
    }

    return 0;
}