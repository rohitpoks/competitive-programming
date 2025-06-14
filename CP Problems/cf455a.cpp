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
#include <stack>
#include <cassert>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<ll> inp(n);
 for (int i = 0; i < n; i++) {
  cin >> inp[i];
 }

 vector<pair<ll, ll> > a;
 map<ll, ll> m;
 ll max_el = 0;
 for (int i = 0; i < n; i++) {
  m[inp[i]]++;
  max_el = max(max_el, inp[i]);
 }

 vector<ll> dp(max_el + 1, 0);
 dp[1] = m[1];
 for (ll i = 2; i <= max_el; i++) {
  dp[i] = max(dp[i - 1], dp[i - 2] + i * m[i]);
  // cout << dp[i] << endl;
 }

 cout << dp[max_el];
 return 0;
}