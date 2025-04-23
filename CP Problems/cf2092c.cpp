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

int find_max(vector<int>& arr) {
  int res = arr[0];
  for (int i : arr) {
    res = max(res, i);
  }

  return res;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);

 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> arr(n);
  int o = 0;
  int e = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    o += (arr[i] & 1);
  }

  e = n - o;

  if (e == 0 || o == 0) {
    cout  << find_max(arr) << '\n';
    continue;
  }


  ll res = 0;
  for (int i = arr.size() - 1; i >= 0; i--) {
    // res is guaranteed to be even
    res += arr[i];
  }

  int diff = o - 1;
  cout << res - diff << '\n';
 }
 return 0;
}