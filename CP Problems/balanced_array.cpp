#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int main()
{

 int k;
 cin >> k;
 while (k > 0)
 {
  k--;
  int n;
  cin >> n;
  int arr[n];
  if (n / 2 % 2 == 1)
  {
   cout << "NO" << endl;
   continue;
  }
  else
  {
   cout << "YES" << endl;
  }
  int cur = 1;
  for (int j = 0; j < n / 2; j++)
  {
   arr[j] = cur;
   cur += 4;
  }
  for (int j = n / 2; j < n; j++)
  {
   arr[j] = j % 2 == 0 ? arr[j - n / 2] + 1 : arr[j - n / 2] - 1;
  }
  for (int j = n - 1; j >= 0; j--)
  {
   cout << arr[j] << ' ';
  }
  cout << endl;
 }

 return 0;
}