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
int score(int n) {
 int s = 0;
 while (n % 10 == 0 && n != 0) {
  s++;
  n /= 10;
 }
 return s;
}

int length(int n) {
 int s = 0;
 while (n != 0) {
  s++;
  n /= 10;
 }
 return s;
}
int main() {
 ios_base::sync_with_stdio(false);
 int q;
 cin >> q;
 while (q--) {
  int m, n;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
   cin>> arr[i];
  }  
  vector<pair<int, int> > p(n);
  for (int i = 0; i < n; i++) {
   p[i].second = arr[i];
   p[i].first = score(arr[i]);
  }
  ll ans = 0;
  sort(p.begin(), p.end(), greater<pair<int, int> >());
  for (int i = 0; i < n; i += 2) {
   // odd zeros: remove
   ans -= p[i].first;
  }
  // add all lengths
  for (int i = 0; i < n; i++) {
   ans += length(arr[i]);
  }
  if (ans >= m + 1) cout << "Sasha\n";
  else cout << "Anna\n";
 }
 return 0;
}