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


ll max_subarray_sum(vector<ll>& a) {
  assert(a.size() > 0);
  int n = a.size();
  ll ans = a[0];
  ll cur = ans;
  for (int i = 1; i < n; i++) {
    // either start a new subsequence at i, or continue the current subsequence
    cur = max(a[i], cur + a[i]);
    ans = max(ans, cur);
  }

  return ans;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // negative, posit0ive, negative, max, positive
  // find max sum
  // case 1: k > what we have
  // in this case, for the region containing 0, make it equal to k
  // we want to get to 33
  // max -> 30,  -ve -31,  posi0tive 15,  -ve -40
  // max -> 30,  -31,  32,  -40


  // case 2: k == what we have
  // done
  

  // case 3: k < what we have
  // make sure the sum of elements in between the 0s is <= k
  // and then, select a zero_index to fill and fill everything else w. -10^18
  ll ans = max_subarray_sum(a);
  int index_of_zero = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') index_of_zero = i;
  }

  if (index_of_zero == -1) {
    if (ans == k) {
      cout << "Yes\n";
      for (ll i : a) cout << i << ' ';
      cout << '\n';
    }
    else {
      cout << "No\n";
    }

    continue;
  }

  if (ans > k) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '0' && i != index_of_zero) {
        a[i] = -1e12;
      }
    }
  }
  int left = index_of_zero;
  int right = index_of_zero;
  assert(index_of_zero >= 0 && index_of_zero < n);
  // at least one zero to modify
  ll l_sum = 0;
  ll r_sum = 0;
  ll cur = 0;
  for (int i = index_of_zero; i < n; i++) {
    cur += a[i];
    if (cur >= r_sum) {
      r_sum = cur;
      right = i;
    }
  }

  cur = 0;
  for (int i = index_of_zero; i >= 0; i--) {
    cur += a[i];
    if (cur >= l_sum) {
      l_sum = cur;
      left = i;
    }
  }

  // cout << "lsum is " << l_sum << " and left is " << left << " and rsum is " << r_sum << " and right is " << right << endl;
  ll total = l_sum + r_sum;
  a[index_of_zero] = k - total;
  ll res = max_subarray_sum(a);
  if (res == k) {
    cout << "Yes\n";
    for (ll i : a) cout << i << ' ';
    cout << '\n';
  } else {
    cout << "No\n";
    // for (int i : a) cout << i << endl;
  }
 }
 return 0;
}