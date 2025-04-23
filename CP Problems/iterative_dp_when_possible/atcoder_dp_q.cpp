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
#include <cassert>

using ll = long long;
using namespace std;


// one common operatoin that we keep performing is finding the
// next power of two that is at least as big as x
// i.e. 2 ^ floor(log2(x))
// we can do this in O(log(x)) time
int next_power_2(int x) {
  if (x == 0) return 0;

  int shift_amt = 0;
  int res_shift_amt = 0;
  while (x > 0) {
    shift_amt++;
    x /= 2;
    if (x & 1) res_shift_amt = shift_amt;
  }

  return 1 << (res_shift_amt);
}

// build tree for indices [l, r) and return sum[l, r)
long long build_tree(int root_idx, vector<ll>& tree, vector<ll>& arr, const ll IDENTITY_VAL) {
  // build tree rooted at root_idx
  // at last level
  if ((2 * root_idx) >= tree.size()) {
    int leftmost_idx = next_power_2(root_idx);
    int arr_idx = root_idx - leftmost_idx;
    if (arr_idx >= arr.size()) {
      return tree[root_idx] = IDENTITY_VAL;
    }

    return tree[root_idx] = arr[arr_idx];
  }

  ll left = build_tree(root_idx * 2, tree, arr, IDENTITY_VAL);
  ll right = build_tree(root_idx * 2 + 1, tree, arr, IDENTITY_VAL);
  // TODO: change operation
  return tree[root_idx] = max(left, right);
}


// never call range_max_query_helper directly!
// n: array's size rounded up to the nearest power of 2
// l: left index of array (inclusive)
// r: right index of array (exclusive)
// root_idx: index of the root (to consider whole tree, call w. 1)
// IDENTITY_VAL: what's a value that won't change the query result?
// i.e. for all x, IDENTITY_VAL (operation) x = x
// for sum, IDENTITY_VAL is 0, for finding min among integers, it's INT_MAX etc.
long long range_max_query_helper(int root_idx, int l, int r, vector<ll>& tree, vector<ll>& arr, ll IDENTITY_VAL, int n) {
  // range sum query: return arr[l, r)
  assert(root_idx >= 0 && root_idx < tree.size());
  // first, figure out which array indices the root covers
  int a_l = ((ll) n * (ll) root_idx) / next_power_2(root_idx) - n;
  int a_r = a_l + n / next_power_2(root_idx);

  // case 1: root doesn't cover range
  if (a_l >= r || a_r <= l) return IDENTITY_VAL;
  // case 2: root overlaps range fully
  if (a_l >= l && a_r <= r) return tree[root_idx];
  // case 3: root covers range partially
  // TODO: change operation
  return max(range_max_query_helper(root_idx * 2, l, r, tree, arr, IDENTITY_VAL, n), range_max_query_helper(root_idx * 2 + 1, l, r, tree, arr, IDENTITY_VAL, n));
}

long long range_max_query(int l, int r, vector<ll>& tree, vector<ll>& arr, ll IDENTITY_VAL) {
  int n = pow(2, ceil(log(arr.size())/log(2)));
  return range_max_query_helper(1, l, r, tree, arr, IDENTITY_VAL, n);
}

// never call update_helper directly!
// arr_idx -> idx of array to update
// new_val -> new value of arr[arr_idx]
// root_idx -> subtree is rooted at root_idx
// n -> nearest next power of 2 of arr.size()
ll update_helper(int arr_idx, ll new_val, int root_idx, vector<ll>& tree, int n, vector<ll>& arr, int IDENTITY_VAL) {
  // update arr[idx] for tree rooted at root_idx
  if (root_idx >= tree.size()) return IDENTITY_VAL;
  assert(arr_idx >= 0 && arr_idx < arr.size());
  // first, figure out which array indices the root covers
  int a_l = ((ll) n * (ll) root_idx) / next_power_2(root_idx) - n;
  int a_r =  a_l + n / next_power_2(root_idx);
  // does the root even cover arr_idx?
  if (arr_idx < a_l || arr_idx >= a_r) return tree[root_idx];
  if (a_l == a_r - 1) {
    tree[root_idx] = new_val;
    return new_val;
  }
  
  // TODO: post order dfs update
  ll left_min = update_helper(arr_idx, new_val, root_idx * 2, tree, n, arr, IDENTITY_VAL);
  ll right_min = update_helper(arr_idx, new_val, root_idx * 2 + 1, tree, n, arr, IDENTITY_VAL);
  return tree[root_idx] = max(left_min, right_min);
}


void update(int arr_idx, ll new_val, vector<ll>& tree, vector<ll>& arr, int IDENTITY_VAL)  {
  int n = pow(2, ceil(log(arr.size())/log(2)));
  update_helper(arr_idx, new_val, 1, tree, n, arr, IDENTITY_VAL);
  arr[arr_idx] = new_val;
}


int main() {
 ios_base::sync_with_stdio(false);
 int n;
 cin >> n;
 vector<ll> h(n);
 vector<ll> a(n);
 for (int i = 0; i < n; i++) {
  cin >> h[i];
 }

 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }

 vector<ll> dp(n + 1, 0);
 int next_power_of_two = pow(2, ceil(log(dp.size())/log(2)));
 vector<ll> tree(2 * next_power_of_two, -1);
 build_tree(1, tree, dp, -1);
 // dp[i] -> max score of flowers plucked if min height is i
 // dp[i] -> v_i + max dp[j] for all j = i + 1, ..., n - 1
 // use a segment tree to keep track of max

 for (int i = n - 1; i >= 0; i--) {
  if (h[i] == n) {
    dp[h[i]] = a[i];
    update(h[i], dp[h[i]], tree, dp, -1);
    continue;
  } 

  dp[h[i]] = range_max_query(h[i] + 1, dp.size(), tree, dp, -1) + a[i];
  update(h[i], dp[h[i]], tree, dp, -1);
 }

 ll res = 0;
 for (ll i : dp) {
  res = max(res, i);
 }

 cout << res << '\n';
 return 0;
}