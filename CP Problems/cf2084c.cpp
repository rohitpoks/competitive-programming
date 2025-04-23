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


int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> v1(n + 1);
  vector<int> v2(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> v1[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> v2[i];
  }

  // count number of 1/2 transpositions
  int one = 0;
  int two = 0;
  int one_element = 0;
  map<int, int> v1_to_v2;
  map<int, int> v2_to_v1;
  for (int i = 1; i <= n; i++) {
    v1_to_v2[v1[i]] = v2[i];
    v2_to_v1[v2[i]] = v1[i];
  }

  for (int i = 1; i <= n; i++) {
    if (v1_to_v2[i] == v2_to_v1[i]) {
      if (v1_to_v2[i] == i) {
        one++;
        one_element = i;
      }
      else two++;
    }
  }

  if (n % 2) {
    if (one != 1 || two != n - 1) {
      cout << -1 << '\n';
      continue;
    }
  } else {
    if (two != n) {
      cout << -1 << '\n';
      continue;
    }
  }

  vector<int> correct_order(n);
  set<int> nums;
  for (int i = 1; i <= n; i++) nums.insert(i);
  int l = 0;
  int r = n - 1;
  // mid: place it first in nums
  if (one) {
    correct_order[n / 2] = one_element;
    nums.erase(one_element);
  }
  while (l < r) {
    correct_order[l] = *nums.begin();
    correct_order[r] = v1_to_v2[correct_order[l]];
    nums.erase(correct_order[l]);
    nums.erase(correct_order[r]);
    l++;
    r--;
  }

  // finally decide the order
  correct_order.insert(correct_order.begin(), 0);
  // cout << "correct order " << endl;
  // for (int i : correct_order) cout << i << ' ';
  // cout << endl;
  vector<pair<int, int> > res = order(correct_order, v1);
  cout << res.size() << '\n';
  for (const auto& p : res) {
    cout << p.first << ' ' << p.second << '\n';
  }
 }


// debug
// vector<int> v1 = {0, 1, 2, 5, 3, 4};
// vector<int> v2 = {0, 2, 5, 1, 3, 4};
// vector<pair<int, int> > res =  order(v1, v2);
// for (const auto& p : res) {
//   cout << p.first << ' ' << p.second << endl;
// }
// end debug
 return 0;
}