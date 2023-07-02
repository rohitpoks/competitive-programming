#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int main()
{

 int n;
 cin >> n;
 bool arr[n + 1];
 for (int i = 0; i < n; i++)
 {
  arr[i] = false;
 }
 for (int i = 0; i < n - 1; i++)
 {
  int j;
  cin >> j;
  arr[j - 1] = true;
 }
 int res = 1;
 for (int i = 0; i < n; i++)
 {
  if (!arr[i])
   res = i + 1;
 }
 cout << res;
 return 0;
}