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

using ll = long long;
using namespace std;

const int SIZE = 1000000;
vector<ll> tree(SIZE);
vector<int> lb(SIZE);
vector<int> rb(SIZE);
vector<int> arr(SIZE);

// iterative build function
void build(int cur, int n) {
 // l and r inclusive
 // n: number of elements in tree (1-indexed)
 for (int i = n-1; i < 2*n-1; i++) {
  int arr_ind = i - n + 1;
  tree[i] = arr[arr_ind];
  lb[i] = arr_ind;
  rb[i] = arr_ind;
 }
 for (int i = n-2; i >= 0; i--) {
  tree[i] = min(tree[i*2+1], tree[i*2+2]);
  lb[i] = lb[i*2+1];
  rb[i] = rb[i*2+2];
  cout << tree[i] << endl;
 }
}

ll minQuery(int cur, int a, int b) {
 // full coverage
 if (lb[cur] >= a && rb[cur] <= b) return tree[cur];
 // partial coverage
 if ((a >= lb[cur] && a <= rb[cur]) || (b <= rb[cur] && b >= lb[cur])) return min(minQuery(2*cur+1, a, b), minQuery(cur*2+2, a, b));
 // return max if no converage
 return INT_MAX;
}


int main() {
 ios_base::sync_with_stdio(false);
 int n, q;
 cin >> n >> q;
 for (int i = 0; i < n; i++) {
  cin >> arr[i];
 }

 build(0, n);


 for (int i = 0; i < q; i++) {
  int a, b;
  cin >> a >> b;
  a--;
  b--;
  cout << minQuery(0, a, b) << '\n';
 }
 
 return 0;
}