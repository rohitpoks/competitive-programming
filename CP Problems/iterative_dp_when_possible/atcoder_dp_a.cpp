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
 // dp(i) -> min cost to get from index i to n - 1
 int n;
 cin >> n;
 vector<int> height(n);
 vector<ll> memo(n + 1);
 memo[n] = 0;
 memo[n - 1] = 0;
 ll res;
 for (int i = 0; i < n; i++) {
  cin >> height[i];
 }

 for (int i = n - 2; i >= 0; i--) {
  if (i + 1 < n) {
    memo[i] = memo[i + 1] + abs(height[i] - height[i+1]);
  }

  if (i + 2 < n) {
    memo[i] = min(memo[i], memo[i + 2] + abs(height[i] - height[i + 2]));
  }
 }

 cout << memo[0];
 return 0;
}