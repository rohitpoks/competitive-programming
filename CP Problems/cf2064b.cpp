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
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  map<int, int> count;
  for (int i : arr) {
    count[i]++;
  }

  int longest = 0;
  int cur = 0;
  int l = -1;
  int r = -1;
  int k = 0;
  for (int i : arr) {
    if (count[i] == 1) {
      cur++;
    } else {
      cur = 0;
    }

    if (cur > longest) {
      longest = cur;
      l = k - longest + 1;
      r = k;
    }

    k++;
  }

  if (longest == 0) {
    cout << 0 << '\n';
    continue;
  }

  cout << l + 1 << ' ' << r + 1<< '\n';
 }

 return 0;
}