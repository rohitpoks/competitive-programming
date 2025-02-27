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
    int n;
    cin >> n;
    if (n % 2) {
      cout << n << '\n';
      for (int i = 1; i <= n; i++) {
        cout << i << ' ';
      }

      cout << '\n';
      continue;
    }
    int count = 0;
    int last1 = 0;
    for (int i = n; i > 0; i /= 2) {
      count++;
      if (i % 2) { 
        last1 = count;
      }
    }

    ll ans = pow(2, last1) - 1;
    int n_comp = 0;
    int temp_n = n;
    for (int i = 0; i < last1; i++) {
      if (temp_n % 2 == 0) n_comp += pow(2, i);
      temp_n /= 2;
    }

    cout << ans << '\n';
    for (int i = 1; i < n; i++) {
      if (i == n_comp) continue;
      cout << i << ' ';
    }
    cout << n_comp << ' ';
    cout << n << '\n';
  }
 return 0;
}