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
            cout << j + 1;
        }
        cout << endl;
    }
    cout << "\n\n";
    for (int i = 0; i < count; i++)
    {
        for (int j = count; j > i; j--)
        {
            cout << count-j+1;
        }
        cout << endl;
    }
    cout << "\n\n";
    int k=1;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << k;
        }
        k++;
        cout << endl;
    }


    return 0;
}