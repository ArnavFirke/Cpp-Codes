#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count;
    cout << "enter value of n:";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n\n";
    for (int i = 0; i < count; i++)
    {
        for (int j = i; j < count; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}