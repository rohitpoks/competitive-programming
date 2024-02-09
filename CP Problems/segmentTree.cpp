#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>
#include <numeric>

using ll = long long;
using namespace std;

long long build_tree(vector<int>& left, vector<int>& right, vector<long long>& tree, vector<int>& arr, int cur, int l, int r) {
 
 left[cur] = l;
 right[cur] = r;
 if (l == r) {
  tree[cur] = arr[l];
  return arr[l];
 }
 int mid = (l + r)/2;
 tree[cur] = build_tree(left, right, tree, arr, 2*cur+1, l, mid) + build_tree(left, right, tree, arr, 2*cur+2, mid+1, r);
 return tree[cur];
}

ll sum(int a, int b, vector<ll>& tree, vector<int>& left, vector<int>& right, vector<int>& arr, int cur) {
 //          0-7
 //    0-3         4-7
 // 0-1   2-3   4-5   6-7
 // 0 1   2 3   4 5   6 7
 if (a <= left[cur] && b >= right[cur]) return tree[cur];
 if ((a <= right[cur] && a >= left[cur]) || (b >= left[cur] && b <= right[cur])) return sum(a, b, tree, left, right, arr, cur * 2 + 1) + sum(a, b, tree, left, right, arr, cur * 2 + 2);
 
 return 0;
}

int main() {
 ios_base::sync_with_stdio(false);
 int n, q;


 cin >> n >> q;
 vector<long long> tree(1000000, 0);
 vector<int> arr(1000000);
 vector<int> left(1000000, 0);
 vector<int> right(1000000, 0);

 for (int i = 0; i < n; i++) {
  cin >> arr[i];
 }

 build_tree(left, right, tree, arr, 0, 0, n-1);
 for (int i = 0; i < q; i++) {
  int a, b;

  cin >> a >> b;
  a--;
  b--;
 cout << sum(a, b, tree, left, right, arr, 0) << '\n';
 }
 return 0;
}