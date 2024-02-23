#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>

using ll = long long;
using namespace std;


ll choose2(ll a) {
 if (a == 1) return 0;
 return a * (a-1) / 2;
}
int main() {
 ios_base::sync_with_stdio(false);
 int n;
 cin >> n;
 vector<ll> balls(n);
 unordered_map<int, ll> map;
 for (int i = 0; i < n; i++) {
  cin >> balls[i];
  if (map.count(balls[i]) == 0) map[balls[i]] = 0;
  map[balls[i]]++;
 }

 ll res = 0;

 for (pair<int, ll> p: map) {
  res += choose2(p.second);
 }

 for (int i = 0; i < balls.size(); i++) {
  ll count = map[balls[i]];
  cout << (res - choose2(count) + choose2(count - 1)) << '\n';
 }

 return 0;
}