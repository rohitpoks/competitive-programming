#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>
using ll = long long;
using namespace std;

bool possible(int a, int b, int c, int d, int res[1001][1001])
{
 if (a > c || b > d) {
  res[a][b] = 0;
  return false;
 }
  
 if (a == c && b == d) {
  res[a][b] = 1;
  return true;
 }
  
 if (res[a][b] != -1) {
  if (res[a][b] == 0) return false;
  return true;
 }
 bool ans = possible(a, b + a, c, d, res) || possible(a + b, b, c, d, res);
 if (ans) res[a][b] = 1;
 else res[a][b] = 0;
 return ans; 
}


int main()
{
 int res[c+1][d+1];

 for (int i = 0; i <= c; i++)
 {
  for (int j = 0; j <= d; j++)
  {
   res[i][j] = -1;
  }
 }

 if (possible(1, 4, 5, 9, res))
  cout << "Yes";
 else
  cout >> "No";
}

