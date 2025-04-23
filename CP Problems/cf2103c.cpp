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

string solve(int n, int k, const vector<int>& arr) {

  // given an index, how many elements to the left of this are less than or equal to k
  vector<int> left(n, 0);
  // given an index, how many elements to the right of this are less than or equal to k
  vector<int> right(n, 0);

  for (int i = 0; i < n; i++) {
    left[i] += (arr[i] <= k);
    if (i - 1 >= 0) left[i] += left[i-1];
  }

  for (int i = n -1 ; i >= 0; i--) {
    right[i] += (arr[i] <= k);
    if (i + 1 < n) right[i] += right[i+1];
  }

  // check for first condition
  int count = 0;
  double largest_above_50 = 100;
  int bar = -1;
  for (int i = 0; i < n; i++) {
    // looking at bar to index i
    int total = i - bar;
    int actual = left[i];
    if (bar >= 0) actual = left[i] - left[bar];
    if (actual * 2 >= total) {
      count++;
    }

    double here = (double) left[i] / (double) (i + 1);
    if (here < largest_above_50 && here >= 0.5) {
      largest_above_50 = here;
      bar = i;
    }
  }


  if (count > 1) return "YES";
  bar = n;
  count = 0;
  largest_above_50 = 100;
  for (int i = n - 1; i >= 0; i--) {
    int total = bar - i;
    int actual = right[i];
    if (bar < n) actual = right[i] - right[bar];
    if (actual * 2 >= total) {
      // cout << "increased at " << i << ' ';
      // cout << "total is " << total << " and actual is " << right[i] << endl;
      count++;
    }

    double here = (double) right[i] / (double) (n - i);
    // cout << "here at i " << i << " is " << here << endl;
    if (here < largest_above_50 && here >= 0.5) {
      largest_above_50 = here;
      bar = i;
      // cout << "new bar is " << bar << endl;
    }
  }


  if (count > 1) return "YES";
  // cout << "here here " << endl;
  int r = INT_MIN;
  int l = INT_MAX;
  for (int i  = 0; i < n; i++) {
    if (right[i] * 2 >= n - i) {
      r = max(r, i);
    }

    if (left[i] * 2 >= i + 1) {
      l = min(l, i);
    }
  }

  if (r != INT_MIN && l != INT_MAX && r - l >= 1) {
    return "YES";
  }

  return "NO";
}
// half of the elements in m1 must be less than k and half
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  int k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  cout << solve(n, k, arr) << '\n';
 }
 return 0;
}