#include <iostream>
using namespace std;
class Binary
{
private:
    string s;
    bool chk_bin(void);

public:
    void read(void);
    void comp(void);
};

void Binary::read(void)
{
    cout << "Enter the binary number: ";
    cin >> s;
}

bool Binary::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1') // (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect Binary format" << endl;
            return false;
        }
    }
    cout << "Given number is in Binary format" << endl;
    return true;
}
void Binary::comp(void)
{
    if (chk_bin())
    {

        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '0')
                s.at(i) = '1';
            else if (s.at(i) == '1')
                s.at(i) = '0';
        }
        cout << "1's complement is: " << s << endl;
    }
    else
        cout << "Cannot find 1's compliment as not in Binary format" << endl;
}

int main()
{
    Binary b;
    b.read();
    b.comp();
    return 0;
}
