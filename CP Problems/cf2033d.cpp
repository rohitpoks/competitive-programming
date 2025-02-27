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

int solve(const vector<int>& arr) {
  set<ll> s;
  s.insert(0);
  ll ps = 0;
  int res = 0;
  for (int i = 0; i < arr.size(); i++) {
    ps += arr[i];
    if (s.count(ps)) {
      res++;
      s = {0};
      ps = 0;
    }

    s.insert(ps);
  }

  return res;
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << solve(arr) << '\n';
 }
 return 0;
}