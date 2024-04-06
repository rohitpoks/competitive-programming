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
 cin  >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
   cin >> b[i];
   b[i]--;
  }
  // b[i]: ith index that turns into 0
  vector<pair<int, int> > m;
  for (int i = 0; i < n; i++) {
   pair<int, int> p;
   p.first = a[i];
   p.second = i;
   m.push_back(p);
  }
  sort(m.begin(), m.end(), greater<pair<int,int> >());
  // m[i].first: (n-i)th order of a
  // m[i].second: index that belongs to this (n-i)th order in a
  vector<bool> inUse(n, false);
  vector<bool> cantUse(n, false);
  int useNext = 0;
  int count = 0;
  ll best = 0;
  ll bestK = 0;
  ll mini = LONG_LONG_MAX;
  int removeNext = 0;
  for (int k = 1; k <= n; k++) {
   while (count != k && useNext < n) {
    // insert next avail
    if (!cantUse[m[useNext].second]) {
     inUse[m[useNext].second] = true;
     mini = m[useNext].first;
     count++;
    }
    useNext++;
   }
   if (best < (ll) count * mini) {
    best = (ll) count * mini;
    bestK = count;
   }
   // next number currently in use, remove it
   // if (used.count(a[b[removeNext]]) > 0) {
    if (inUse[b[removeNext]]) {
    count--;
   }
   cantUse[b[removeNext]] = true;
   removeNext++;
   
  }
  cout << best << ' ' << bestK << '\n';
 }
 return 0;
}