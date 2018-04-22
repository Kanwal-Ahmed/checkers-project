#include<iostream>
#include<string>
using namespace std;
class check
{
private:
  int i, j, num = 8;

public:
  void display()
  {
    for (i = 0;i<num;i++)
    {
      for (j = 0;j <= num;j++)
      {
        system("COLOR F0");
        cout << "\xDB";
        cout << "\xDB";
        cout << " ";
        cout << " ";
      }
      cout << "\n";
      if (i % 2 == 0)
      {
        cout << " ";
        cout << " ";
      }
    }
  }

};
