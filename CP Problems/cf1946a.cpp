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
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  sort(a.begin(), a.end());
  int md = ((a.size() + 1)/ 2); 
  md--;
  int x = md - 1;
  int y = md + 1;
  while (y < n && a[y] == a[md]) y++;
  cout << y - md << '\n';
 }
 return 0;
}