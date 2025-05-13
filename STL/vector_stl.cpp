#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    v.resize(10);
    for (int i = 0; i < 10; i++)
        cin >> v[i];

    // for (int i = 0; i < 10; i++)
    // cout<<v[i]<<" ";
    // cout<<endl;

    vector<int>::iterator it;

    sort(v.begin(), v.end());
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}