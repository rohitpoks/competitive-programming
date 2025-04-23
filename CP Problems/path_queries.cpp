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


using ll = long long;
using namespace std;

// one common operation that we keep performing is finding the
// largest power of two that is at most as big as x
// i.e. 2 ^ floor(log2(x))
// we can do this in O(log(x)) time
inline unsigned int lower_power_of_2(unsigned int x) {
    // return the largest power of 2 <= x
    // e.g. lower_power_of_2(20) = 16, lower_power_of_2(16) = 16,
    //      lower_power_of_2(0) = 0
    if (x == 0) return 0;
    // __builtin_clz(x) -> number of leading zeros in x (32 bits).
    // 31 - __builtin_clz(x) -> index of the highest set bit (0-based).
    // 1u << that index gives us the highest power of 2 <= x
    return 1u << (31 - __builtin_clz(x));
}

// similarly, calculate 2 ^ ceil(log2(x))
inline unsigned int upper_power_of_2(unsigned int x) {
    // return the smallest power of 2 >= x
    // e.g. upper_power_of_2(20) = 32, upper_power_of_2(16) = 16,
    //      upper_power_of_2(0) = 0, upper_power_of_2(1) = 1
    if (x == 0) return 0;
    if (x == 1) return 1;
    // x - 1 so we shift the boundary for exact powers
    return 1u << (32 - __builtin_clz(x - 1));
}

// build tree for indices [l, r) and return sum[l, r)
long long build_tree(int root_idx, vector<ll>& tree, vector<ll>& arr, const ll IDENTITY_VAL) {
  // build tree rooted at root_idx
  // at last level
  if ((2 * root_idx) >= tree.size()) {
    int leftmost_idx = lower_power_of_2(root_idx);
    int arr_idx = root_idx - leftmost_idx;
    if (arr_idx >= arr.size()) {
      return tree[root_idx] = IDENTITY_VAL;
    }

    return tree[root_idx] = arr[arr_idx];
  }

  ll left = build_tree(root_idx * 2, tree, arr, IDENTITY_VAL);
  ll right = build_tree(root_idx * 2 + 1, tree, arr, IDENTITY_VAL);
  // TODO: change operation
  return tree[root_idx] = left + right;
}


// never call range_sum_query_helper directly!
// n: array's size rounded up to the nearest power of 2
// l: left index of array (inclusive)
// r: right index of array (exclusive)
// root_idx: index of the root (to consider whole tree, call w. 1)
// IDENTITY_VAL: what's a value that won't change the query result?
// i.e. for all x, IDENTITY_VAL (operation) x = x
// for sum, IDENTITY_VAL is 0, for finding min among integers, it's INT_MAX etc.
long long range_sum_query_helper(int root_idx, int l, int r, vector<ll>& tree, vector<ll>& arr, ll IDENTITY_VAL, int n) {
  // range sum query: return arr[l, r)
  assert(root_idx >= 0 && root_idx < tree.size());
  // first, figure out which array indices the root covers
  int a_l = ((ll) n * (ll) root_idx) / lower_power_of_2(root_idx) - n;
  int a_r = a_l + n / lower_power_of_2(root_idx);

  // case 1: root doesn't cover range
  if (a_l >= r || a_r <= l) return IDENTITY_VAL;
  // case 2: indices covered by root are within [l, r)
  if (a_l >= l && a_r <= r) return tree[root_idx];
  // case 3: root covers range partially
  // TODO: change operation
  return range_sum_query_helper(root_idx * 2, l, r, tree, arr, IDENTITY_VAL, n) + range_sum_query_helper(root_idx * 2 + 1, l, r, tree, arr, IDENTITY_VAL, n);
}

long long range_sum_query(int l, int r, vector<ll>& tree, vector<ll>& arr, ll IDENTITY_VAL) {
  // int n = pow(2, ceil(log(arr.size())/log(2)));
  int n = upper_power_of_2(arr.size());
  return range_sum_query_helper(1, l, r, tree, arr, IDENTITY_VAL, n);
}

// never call update_helper directly!
// arr_idx -> idx of array to update
// new_val -> new value of arr[arr_idx]
// root_idx -> subtree is rooted at root_idx
// n -> nearest next power of 2 of arr.size()
ll update_helper(int arr_idx, ll new_val, int root_idx, vector<ll>& tree, int n, vector<ll>& arr) {
  // update arr[idx] for tree rooted at root_idx
  if (root_idx >= tree.size()) return 0;
  assert(arr_idx >= 0 && arr_idx < arr.size());
  // first, figure out which array indices the root covers
  int a_l = ((ll) n * (ll) root_idx) / lower_power_of_2(root_idx) - n;
  int a_r =  a_l + n / lower_power_of_2(root_idx);
  // does the root even cover arr_idx?
  if (arr_idx < a_l || arr_idx >= a_r) return tree[root_idx];
  if (a_l == a_r - 1) {
    return tree[root_idx] = new_val;
  }
  ll new_left = update_helper(arr_idx, new_val, root_idx * 2, tree, n, arr);
  ll new_right = update_helper(arr_idx, new_val, root_idx * 2 + 1, tree, n, arr);

  // TODO: update policy
  return tree[root_idx] = new_left + new_right;
}


void update(int arr_idx, ll new_val, vector<ll>& tree, vector<ll>& arr)  {
  // int n = pow(2, ceil(log(arr.size())/log(2)));
  int n = upper_power_of_2(arr.size());
  update_helper(arr_idx, new_val, 1, tree, n, arr);
  arr[arr_idx] = new_val;
}


int populate_idx_from_root(vector<vector<int> >& tree, int p, int root, vector<int>& idx_from_root, vector<int>& leftmost_idx_from_root, int& cur_idx) {
  for (int n : tree[root]) {
    if (n == p) continue;
    leftmost_idx_from_root[root] = min(leftmost_idx_from_root[root], populate_idx_from_root(tree, root, n, idx_from_root, leftmost_idx_from_root, cur_idx));
  }

  cur_idx++;
  idx_from_root[root] = cur_idx;
  if (leftmost_idx_from_root[root] == INT_MAX) {
    leftmost_idx_from_root[root] = cur_idx;
  }

  return leftmost_idx_from_root[root];
}

void populate_path_sum(vector<ll>& path_sum, vector<vector<int> >& tree, int p, vector<ll>& val, int root, ll& cur_path_sum, vector<int>& idx_from_root) {
  cur_path_sum += val[root];
  path_sum[idx_from_root[root]] = cur_path_sum;
  for (int n : tree[root]) {
    if (n == p) continue;
    populate_path_sum(path_sum, tree, root, val, n, cur_path_sum, idx_from_root);
  }

  cur_path_sum -= val[root];
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, q;
 cin >> n >> q;
 vector<vector<int> > tree(n + 1);

 vector<ll> path_sum(n + 1);

 vector<ll> values(n + 1);
 for (int i  = 1; i <= n; i++) {
  cin >> values[i];
 }

 for (int i = 0; i < n - 1; i++) {
  int u, v;
  cin >> u >> v;
  tree[u].push_back(v);
  tree[v].push_back(u);
 }

 ll cur_path_sum = 0;
 vector<int> idx_from_root(n + 1, 0);
 vector<int> leftmost_idx_from_root(n + 1, INT_MAX);
 int cur_idx = 0;
 populate_idx_from_root(tree, -1, 1, idx_from_root, leftmost_idx_from_root, cur_idx);
 // must populate path sum for index_from_root
 populate_path_sum(path_sum, tree, -1, values, 1, cur_path_sum, idx_from_root);
 // next, populate offsets
 vector<ll> offset(n + 2, 0);
 int n_p_t = upper_power_of_2(n + 2);
 vector<ll> tr(2 * n_p_t, 0);
 build_tree(1, tr, offset, 0);
 while (q--) {
  int t;
  cin >> t;
  if (t == 2) {
    int node;
    cin >> node;
    int actual_idx = idx_from_root[node];
    ll o = range_sum_query(0, actual_idx + 1, tr, offset, 0);
    cout << path_sum[actual_idx] + o << '\n';
  } else {
    int node;
    ll new_val;
    cin >> node >> new_val;
    int actual_index = idx_from_root[node];
    ll prev_val = values[node];
    ll new_offset_diff = new_val - prev_val;
    int left =  leftmost_idx_from_root[node];
    update(left, offset[left] + new_offset_diff, tr, offset);
    update(actual_index + 1, offset[actual_index + 1] - new_offset_diff, tr, offset);
    values[node] = new_val;
  }
 }
 return 0;
}