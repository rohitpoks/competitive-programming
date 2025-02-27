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
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int max_val = INT_MIN;
    for (int i = 0; i  < n; i++) {
      int x;
      cin >> x;
      max_val = max(max_val, x);
    }  

    for (int i = 0; i < m; i++) {
      string c;
      int l;
      int r;
      cin >> c;
      cin >> l >> r;
      if (c == "+") {
        if (l <= max_val && max_val <= r) {
          max_val++;
        }
        cout << max_val << " ";
        continue;
      }
      
      if (l <= max_val && max_val <= r) {
        max_val--;
      }

      cout << max_val << " ";
    }
    cout << "\n";
  }
}