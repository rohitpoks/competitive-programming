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
using namespace std;
using ll = long long;
using state = vector<vector<vector<vector<int> > > >;

int dp(bool canSkip, int index, char a, char b, const string& s, state& memo) {
  if (index >= s.size()) {
    return 0;
  }

  if (memo[canSkip][index][a - 'a'][b - 'a'] != -1) return memo[canSkip][index][a - 'a'][b - 'a'];
  int result = INT_MAX;
  if (canSkip) {
    // assume even is even, odd is odd
    if (index % 2 == 0) {
      result = min(result, (a != s[index]) + dp(canSkip, index + 1, a, b, s, memo));
      result = min(result, 1 + dp(false, index + 1, b, a, s, memo));
      return memo[canSkip][index][a - 'a'][b - 'a'] = result;
    }

    result = min(result, (b != s[index]) + dp(canSkip, index + 1, a, b, s, memo));
    result = min(result, 1 + dp(false, index + 1, b, a, s, memo));

    return memo[canSkip][index][a - 'a'][b - 'a'] = result;
  }

  if (index % 2 == 0) {
    result = min(result, (a != s[index]) + dp(canSkip, index + 1, a, b, s, memo));
    return memo[canSkip][index][a - 'a'][b - 'a'] = result;
  }

  return memo[canSkip][index][a - 'a'][b - 'a'] = min(result, (b != s[index]) + dp(canSkip, index + 1, a, b, s, memo));
}
void solve(const string& s, int n) {

  state memo(2, vector<vector<vector<int> > > (n + 1, vector<vector<int> >(26, vector<int>(26, -1))));
  int res = INT_MAX;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      res = min(res, dp(s.size() % 2, 0, i + 'a', j + 'a', s, memo));
    }
  }
  if (res == 0 && (s.size() % 2 == 1)) cout << 1 << '\n';
  else cout << res << '\n';
}

int main() {
 ios_base::sync_with_stdio(false);

 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  solve(s, n);
 }


 return 0;
}