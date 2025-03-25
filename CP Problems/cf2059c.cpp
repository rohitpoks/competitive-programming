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

bool can_construct(map<int, int> a, int n) {
  while (n > 0 && ((--a.upper_bound(n)) != a.end())) {
    a[(--a.upper_bound(n))->first]--;
    if (!a[(--a.upper_bound(n))->first]) 
    n--;
  }
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  vector<vector<int> > arr(n, vector<int>(n, 0));
  for (int i  = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }

    reverse(arr.begin(), arr.end());
  }

  map<int, int> count;
  for (int i  = 0; i < n; i++) {
    int total = 0;
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 1) {
        total++;
      } else {
        count[total]++;
        break;
      }
    }
  }

  int l = 0;
  int r = n;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (can_construct(count, n)) {
      l = m;
    } else {
      r = m;
    }
  }
 }
 
 return 0;
}