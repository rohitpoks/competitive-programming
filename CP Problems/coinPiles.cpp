#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{

 int n;
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  int a;
  int b;
  cin >> a;
  cin >> b;
  if (a < b)
  {
   int temp = b;
   b = a;
   a = temp;
  }
  if ((2 * b - a) % 3 == 0 && (2* b - a) >= 0)
  {
   cout << "YES" << endl;
  }
  else
  {
   cout << "NO" << endl;
  }
 }

 return 0;
}
