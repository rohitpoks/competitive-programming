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

bool can_break_down(map<int, int>& count, int n) {
  if (n == 0) return false;
  if (count[n]) {
    count[n]--;
    return true;
  }

  if (n % 2 == 0) {
    return can_break_down(count, n / 2) && can_break_down(count, n / 2);
  }

  return can_break_down(count, n / 2) && can_break_down(count, n / 2 + 1);
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  vector<int> arr(m);
  ll sum_a = 0;
  ll sum_b = 0;
  map<int, int> count;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum_a += x;
    count[x]++;
  }

  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    sum_b += arr[i];
  }

  if (sum_a != sum_b) {
    cout << "NO\n";
    continue;
  }

  bool is_done = false;
  for (int i : arr) {
    if (!can_break_down(count, i)) {
      cout << "NO\n";
      is_done = true;
      break;
    }
  }

  if (is_done) continue;
  cout << "YES\n";
 }
 return 0;
}