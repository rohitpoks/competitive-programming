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
long long build_tree(int root_idx, vector<ll>& tree, vector<int>& arr, const ll IDENTITY_VAL) {
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
long long range_sum_query_helper(int root_idx, int l, int r, vector<ll>& tree, vector<int>& arr, ll IDENTITY_VAL, int n) {
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
  return range_sum_query_helper(root_idx * 2, l, r, tree, arr, IDENTITY_VAL, n) + range_sum_query_helper(root_idx * 2 + 1, l, r, tree, arr, IDENTITY_VAL, n);
}

long long range_sum_query(int l, int r, vector<ll>& tree, vector<int>& arr, ll IDENTITY_VAL) {
  int n = pow(2, ceil(log(arr.size())/log(2)));
  return range_sum_query_helper(1, l, r, tree, arr, IDENTITY_VAL, n);
}

// never call update_helper directly!
// arr_idx -> idx of array to update
// new_val -> new value of arr[arr_idx]
// root_idx -> subtree is rooted at root_idx
// n -> nearest next power of 2 of arr.size()
ll update_helper(int arr_idx, ll new_val, int root_idx, vector<ll>& tree, int n, vector<int>& arr) {
  // update arr[idx] for tree rooted at root_idx
  if (root_idx >= tree.size()) return 0;
  assert(arr_idx >= 0 && arr_idx < arr.size());
  // first, figure out which array indices the root covers
  int a_l = ((ll) n * (ll) root_idx) / next_power_2(root_idx) - n;
  int a_r =  a_l + n / next_power_2(root_idx);
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


void update(int arr_idx, ll new_val, vector<ll>& tree, vector<int>& arr)  {
  int n = pow(2, ceil(log(arr.size())/log(2)));
  update_helper(arr_idx, new_val, 1, tree, n, arr);
  arr[arr_idx] = new_val;
}

// return the first node of postorder traversal for tree rooted at r
int dfs(vector<vector<int> >& tree, int r, int p, int& cur_id, vector<int>& node_to_arr_idx, vector<int>& leftmost_idx) {
  if ((tree[r].size() == 1 && tree[r][0] == p) || (tree[r].size() == 0)) {
    // leaf node
    cur_id++;
    node_to_arr_idx[r] = cur_id;
    leftmost_idx[r] = cur_id;
    return leftmost_idx[r];
  }

  for (int c : tree[r]) {
    if (c == p) continue;
    leftmost_idx[r] = min(leftmost_idx[r], dfs(tree, c, r, cur_id, node_to_arr_idx, leftmost_idx));
  }

  cur_id++;
  // cout << "at node " << r << " pre order number is " << cur_id << endl;
  node_to_arr_idx[r] = cur_id;
  return leftmost_idx[r];
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, q;
 cin >> n >> q;
 vector<int> temp(n + 1);
 for (int i = 1; i <= n; i++) {
  cin >> temp[i];
 }

 vector<vector<int> > tree(n + 1);
 for (int i = 0; i < n - 1; i++) {
  int u, v;
  cin >> u >> v;
  tree[u].push_back(v);
  tree[v].push_back(u);
 }

 vector<int> node_to_arr_idx(n + 1);
 vector<int> leftmost_idx(n + 1, INT_MAX);
 vector<int> arr(n + 1);
 int cur_id = 0;
 dfs(tree, 1, -1, cur_id, node_to_arr_idx, leftmost_idx);
 for (int i = 1; i <= n; i++) {
  arr[node_to_arr_idx[i]] = temp[i];
 }

  // cout << "node number to preorder id" << endl;
//  for (int i = 1; i <= n; i++) {
//   cout << i << ":" << node_to_arr_idx[i] << " ";
//  }
//  cout << endl;

//  cout << "leftmost idx" << endl;
//  for (int i = 1; i <= n; i++) {
//   cout << i << ":" << leftmost_idx[i] << " ";
//  }

 int next_power_of_two = pow(2, ceil(log(n + 1)/log(2)));
 vector<ll> segment_tree(2 * next_power_of_two, 0);
 build_tree(1, segment_tree, arr, 0);
 while (q--) {
  int type;
  cin >> type;
  if (type == 1) {
    int root;
    cin >> root;
    int x;
    cin >> x;
    update(node_to_arr_idx[root], x, segment_tree, arr);
  } else {
    int root;
    cin >> root;
    // cout << "right is " << node_to_arr_idx[root] + 1;
    // cout << "leftmost idx is " << leftmost_idx[root] << endl;
    cout << range_sum_query(leftmost_idx[root], node_to_arr_idx[root] + 1, segment_tree, arr, 0) << '\n';
  }
 }
 return 0;
}