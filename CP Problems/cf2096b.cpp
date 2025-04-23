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

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);

 int t;
 cin >> t;
 int n, k;
 while (t--) {
  cin >> n >> k;
  vector<ll> v1(n);
  vector<ll> v2(n);
  for (int i = 0; i < n; i++) {
    cin >> v1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v2[i];
  }

  // k - 1 > take the max
  // for the n: 
  vector<pair<int, int> > sum_max;
  for (int i = 0; i < n; i++) {
    sum_max.push_back({max(v1[i], v2[i]), min(v1[i], v2[i])});
  }

  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += sum_max[i].first;
  }

  vector<ll> t;
  for (int i = 0; i < n; i++) {
    t.push_back(sum_max[i].second);
  }

  sort(t.begin(), t.end(), greater<int>());
  // take k - 1 of these
  for (int i  =0; i < k - 1; i++) {
    res += t[i];
  }

  res += 1;
  cout << res << '\n';
 }
 return 0;
}