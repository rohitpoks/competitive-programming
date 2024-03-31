#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <climits>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 int q;
 cin >> q;
 while (q--) {
  int n;
  cin >> n;
  vector<string> grid(2);
  cin >> grid[0];
  cin >> grid[1];
  ll opt = 1;
  string res = "";
  int row = 0;
  int col = 0;
  for (int i = 0; i < n; i++) {
   // row, col: current position, is correct
   res += grid[row][col];
   if (col == n-1) break;
   if (row == 0) {
    if (grid[row][col + 1] < grid[1][col]) {
     opt = 1;
     col = col + 1;
    } else if (grid[row][col + 1] == grid[1][col]) {
     opt++;
     col = col + 1;
    } else {
     row = 1;
    }
   } else {
    col++;
   }
  }
  res += grid[1][n-1];
  cout << res << '\n';
  cout << opt << '\n';
 }
 return 0;
}