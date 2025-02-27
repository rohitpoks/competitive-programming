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
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> arr(n);
  priority_queue<int, vector<int>, greater<int> > left;
  priority_queue<int, vector<int>, greater<int> > right;
  for (int i  = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < r; i++) {
    left.push(arr[i]);
  }

  for (int i = l - 1; i < n; i++) {
    right.push(arr[i]);
  }


  ll left_min, right_min = 0;
  int k = r - l + 1;
  while (k--) {
    if (left.size()) {
      cout << left.top() << '\n';
      left_min += left.top();
      left.pop();
    } else if (right.size()) {
      right_min += right.top();
      right.pop();
    }
  }
  
  cout << min(left_min, right_min) << '\n';
 }

 return 0;
}