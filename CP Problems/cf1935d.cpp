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
 int q;
 cin >> q;
 while (q--) {
  int n;
  ll c;
  cin >> n >> c;
  ll res = (c+1)*c/2 + (c+1);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  int even = 0;
  int odd = 0;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) {
   int a = arr[i];
   if (a % 2 == 0) even++;
   else odd++;
   res -= (c + 1 - a);
   if (a % 2 == 0) res -= (a/2 + 1 - even);
   else res -= (a/2 + 1 - odd);
  }
  cout << res << '\n';
 }
 return 0;
}