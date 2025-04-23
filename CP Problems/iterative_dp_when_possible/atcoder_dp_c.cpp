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
 // memo[i][0] -> max possible total points if at index i taro does activity 0
 int n;
 cin >> n;
 vector<int> a(n);
 vector<int> b(n);
 vector<int> c(n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
  cin >> b[i];
  cin >> c[i];
 }


 vector<vector<ll> > memo(n + 1, vector<ll>(3, 0));
 memo[n - 1][0] = a[n-1];
 memo[n - 1][1] = b [n-1];
 memo[n - 1][2] = c[n-1];
 for (int i = n - 2; i >= 0;  i--) {
  // use a at index i
  memo[i][0] = (ll) a[i] + max(memo[i+1][1], memo[i+1][2]);
  // use b at index i
  memo[i][1] = (ll) b[i] + max(memo[i + 1][0], memo[i+1][2]);
  // use c at index i
  memo[i][2] = (ll) c[i] + max(memo[i + 1][1], memo[i+1][0]);
  // cout << memo[i][0] << " at index " << i << endl;
 }

 cout << max(max(memo[0][0], memo[0][1]), memo[0][2]);
 return 0;
}