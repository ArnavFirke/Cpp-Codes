#include <iostream>
#include <string>
using namespace std;
#define size 10

class vector
{
  int arr[size];

public:
  vector()
  {
    for (int i = 0; i < size; i++)
      arr[i] = 0;
  }
  vector(int *a)
  {
    for (int i = 0; i < size; i++)
      arr[i] = a[i];
  }
  void display()
  {
    for (int i = 0; i < size; i++)
      cout << arr[i] << ' ';
    cout << endl;
  }

  friend istream &operator>>(istream &obj, vector &temp)
  {

    for (int i = 0; i < size; i++)
    {
      obj >> temp.arr[i];
    }
    return obj;
  }

  friend ostream &operator<<(ostream &obj, vector &temp)
  {
    for (int i = 0; i < size; i++)
    {
      obj << temp.arr[i] << ' ';
    }
    cout << endl;
    return obj;
  }
  void mult()
  {
    int n;
    cout << "N::";
    cin >> n;
    for (int i = 0; i < size; i++)
    {
      arr[i] = n * arr[i];
    }
  }
};
int main()
{
  vector ac;
  cin >> ac;

  cout << ac;
  ac.mult();
  cout << ac;

  return 0;
}