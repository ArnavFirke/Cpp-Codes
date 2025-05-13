#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> create()
{
    vector<int> v;
    int ele, n;
    cout << "Enter the number of elements:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements: ";
        cin >> ele;
         v.push_back(ele);
    }
    return v;
}
void avg(vector<int> v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << "sum is :" << sum << endl;
    cout << "Avg is :" << sum / v.size() << endl;
}
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}
int main()
{
    vector<int> v1 = create();
    avg(v1);
    return 0;
}

// vector store the marks of n students and compute avg score