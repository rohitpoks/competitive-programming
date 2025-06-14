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

const ll MOD = 1e9 + 7;

ll dp(ll total, vector<ll>& memo) {
  // either pick 1 number or two numbers
  if (total == 0) return 1;
  if (total < 0) return 0;

  if (memo[total] != -1)  return memo[total];
  // {1, 2, 3} -> pick 1: only white
  // pick 2: can pick white or black
  // {1, 2} -> 2 choices

  // {1, 2, 3}
  // {1}, {2, 3}
  ll one = dp(total - 1, memo) % MOD;
  // total * total - 
  ll two = ((((total - 1) * 2) % MOD) * dp(total - 2, memo)) % MOD;
  // pick different rows and columns

  return memo[total] = (one + two) % MOD;
}
// available rows and cols
// {1, 2, 3, 4, 5}
// # of ways of picking 2 or 1
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  ll total = n;
  vector<ll> memo(n + 1, -1);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    if (a == b) total -= 1;
    else total -= 2;
  }

  cout << (dp(total, memo) % MOD) << '\n';
 }
 return 0;
}