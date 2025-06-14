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

vector<ll> solve(vector<ll> a, int n) {
  vector<ll> psum(n + 1, 0);
  // psum[i] -> sum of elements from i to n-1
  for (int i = n - 1; i >= 0; i--) {
    psum[i] = a[i];
    psum[i] += psum[i+1];
  }

  // largest to the left of this
  vector<ll> largestLeft(n + 1, 0);
  ll largest = 0;
  for (int i = 0; i < n; i++) {
    largest = max(largest, a[i]);
    largestLeft[i] = largest;
  }

  vector<ll> res(n);
  for (int i = n - 1; i >= 0; i--) {
    res[i] = psum[i + 1] + largestLeft[i];
    // cout << "largest to the left is " << largestLeft[i] << " and psum is " << psum[i + 1] << endl;
    cout << res[i] << ' ';
  }

  cout << '\n';
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
  vector<ll> a(n);
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i];
  }

  solve(a, n);
 }
 return 0;
}