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

bool is_possible(vector<int> arr, int k , int target, string colors) {
  // return if possible to have all elements <= target in under k steps
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > target) arr[i] = colors[i];
    else {
      arr[i] = '0';
    }
  }

  arr.push_back('R');
  // br0br0b0r
  int total = 0;
  bool found_b = false;
  for (int i : arr) {
    if (i == 'B') found_b = true;
    else if (i == 'R') {
      if (found_b) {
        total++;
      }

      found_b = false;
    }
  }

  return total <= k;
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int l = 0;
  int r = 1;
  for (int i : arr) {
    r = max(r, i);
  }
  
  r++;

  // cout << is_possible(arr, 1, 2, s);
  while (r - l > 1) {
    int m = l + (r-l)/2;
    if (is_possible(arr, k, m, s)) {
      r = m;
    } else {
      l = m;
    }
  }

  // r works for sure, dk about l
  if (is_possible(arr, k, l, s)) cout << l << '\n';
  else cout << r << '\n';
 }

 return 0;
}