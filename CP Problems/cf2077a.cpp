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
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<ll> arr(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  ll res = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i >= n + 1) {
      res -= arr[i];
    } else {
      res += arr[i];
    }
  }

  queue<ll> largest;
  queue<ll> smallest;
  for (int i = 0; i < n + 1; i++) largest.push(arr[i]);
  for (int i = n + 1; i < arr.size(); i++) smallest.push(arr[i]);
  cout << largest.front() << ' ';
  largest.pop();
  cout << res << ' ';
  while (largest.size() && smallest.size()) {
    cout << largest.front() << ' ' << smallest.front() << ' ';
    largest.pop();
    smallest.pop();
  }

  cout << largest.front() << '\n';
 }
 return 0; 
}