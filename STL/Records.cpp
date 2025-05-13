#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Records
{
private:
public:
    int roll;
    string name;
    float marks;

    Records() : roll(0), name(""), marks(0.0) {}

    bool operator==(const Records &i1) // Boolean operators allow you to                                                         create more complex conditional statements
    {
        if (marks == i1.marks) // operator will return 1 if the comparison is true, or 0 if                                          the comparison is false
            return 1;
        return 0;
    }

    bool operator<(const Records &i1)
    {
        if (marks < i1.marks) // operator will return 1 if the comparison is true, or 0 if                                         the comparison is false
            return 1;
        return 0;
    }
};

vector<Records> v;

void setdetails()
{
    Records r;
    cin >> r.name >> r.roll >> r.marks;
    v.push_back(r);
}
bool compare(Records r1, Records r2)
{
    return r1.marks < r2.marks;
}
void show(Records r)
{
    cout << r.name << ' ' << r.roll << ' ' << r.marks << endl;
}

int main()
{
    setdetails();
    setdetails();
    setdetails();
    setdetails();
    cout << endl;
    for_each(v.begin(), v.end(), show);
    cout << endl;
    sort(v.begin(), v.end(), compare);

    return 0;
}