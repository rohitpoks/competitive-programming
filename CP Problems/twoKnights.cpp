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
 for (long i = 1; i <= n; i++)
 {
  if (i == 1)
   cout << 0 << endl;
  else if (i == 2)
   cout << 6 << endl;
  else
  {
   long res = ((i * i) * (i * i - 1) / 2) - 4 * (i - 1) * (i - 2);
   cout << res << endl;
  }
 }
}