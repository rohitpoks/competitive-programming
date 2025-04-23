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
 while (t--) {
  int n;
  cin >> n;
  vector<ll> arr(n);
  set<ll> unique;
  ll res = 1;
  for (int i  =0; i < n; i++) {
    cin >> arr[i];
    unique.insert(arr[i]);
  }

  set<ll> unique_2;
  for (ll i : unique) {
    res *= i;
  }
  
  for (ll i : unique) {
    unique_2.insert(res / i);
  }

  cout << unique.size() << '\n';
 }
 return 0;
}