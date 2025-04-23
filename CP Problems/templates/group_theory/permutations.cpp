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
#include <bit>
#include <bitset>
#include <climits>
#include <cassert>

using ll = long long;
using namespace std;


// assumes v1 and v2 are permutations of 1...n
// assumes 1-indexed!
vector<pair<int, int> > order(vector<int>& v1, vector<int>& v2) {
  // go from v2 to v1 using just transpositions
  int cur = 1;
  int n = v1.size() - 1;
  vector<pair<int, int> > res;
  map<int, int> element_to_v2_idx;
  for (int i = 1; i <= n; i++) element_to_v2_idx[v2[i]] = i;
  while (cur < v1.size()) {
    if (v1[cur] == v2[cur]) {
      cur++;
    } else {
      // v1[cur] -> target of v2, first find where it is
      // cout << "not equal at idx " << cur << endl;
      int left = cur;
      int right = element_to_v2_idx[v1[cur]];
      // swap left, right
      res.push_back({left, right});
      int t = v2[left];
      v2[left] = v2[right];
      v2[right] = t;
      element_to_v2_idx[v2[left]] = left;
      element_to_v2_idx[v2[right]] = right;
      cur++;
    }
  }

  return res;
}