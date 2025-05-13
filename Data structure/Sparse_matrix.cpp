#include <iostream>
#include <string>
using namespace std;
typedef struct matrix
{
    int col;
    int row;
    int value;
} smat;
int main()
{
    smat a[4], b[4]={0};
    cout << "Enter the values in sparse matrix representation:\n";
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i].row;
        cin >> a[i].col;
        cin >> a[i].value;
    }
    getchar();
    int n=a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    if (n > 0)
    {
        int k = 1;
        for (int i = 0; i < a[0].col; i++)
        {
            for (int j = 1; i <= n; j++)
            {
                if (a[j].col == i)
                {
                    b[k].row = a[j].col;
                    b[k].col = a[j].row;
                    b[k].value = a[j].value;
                    k++;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }

    return 0;
}