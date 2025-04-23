#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#include <cassert>

using ll = long long;
using namespace std;


vector<vector<int> > solve(int n, int m, int k) {
  bool should_rev = false;
  bool is_cur_rev = false;
  if (!(m % k)) {
    should_rev = true;
  }


  int next = 1;
  vector<vector<int> > res(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    if ((i % 2) && should_rev) next = k;
    else if (should_rev) next = 1;
    for (int j  = 0; j < m; j++) {
      res[i][j] = next;
      if (should_rev && i % 2) {
        next--;
        if (next == 0) next = k;
      } else {
        next++;
        if (next > k) next = 1;
      }

      if (i > 0 && res[i][j] == res[i-1][j]) {
        // swap res[i][j] and res[i][j-1]
        int temp = res[i][j-1];
        res[i][j-1] = res[i][j];
        res[i][j] = temp;
      }
    }
  }

  return res;
}


// void test() {
//   while (1) {
//     int n, m;
//     n = rand() % 100;
//     n++;
//     m = rand() % 100;
//     m++;
//     int k = rand() % 100;
//     if (k < 2 || ((n * m) % k)) continue;

//     cout << "testing for " << n << "," << m << "," << k << endl;
//     vector<vector<int> > t = solve(n, m, k);
//     for (int i = 0; i < n; i++) {
//       for (int j = 0; j < m; j++) {
//         if (i > 0 && j > 0 && (t[i][j] == t[i-1][j] || t[i][j] == t[i][j-1])) {
//           assert(1 != 1);
//         }
//       }
//     }
//   }
// }

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
//  test();
 cin >> t;
 while (t--) {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int> > res = solve(n, m, k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << res[i][j] << ' ';
    }

    cout << '\n';
  }
 }
 return 0;
}