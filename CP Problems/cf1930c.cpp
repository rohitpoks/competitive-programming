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

 class CustomComparator {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
   if (p1.first - p1.second > p2.first - p2.second) return true;
   if (p1.first - p1.second == p2.first - p2.second && p1.first > p2.first) return true;
   return false;
  }
 };
 int q;
 cin >> q;
 while (q--) {
  int n;
  cin >> n;
  vector<pair<int, int> > arr;
  for (int i = 0; i < n; i++) {
   pair<int, int> p;
   cin >> p.second;
   p.first = p.second + (i + 1); 
   p.second = p.first - i;
   arr.push_back(p);
  }
  sort(arr.begin(), arr.end(), CustomComparator());
  set<int> used;
  vector<int> res;
  for (int i = 0; i < n; i++) {
   cout << arr[i].second << ":" << arr[i].first << endl;
   used.lower_bound()
  }
  for (int i : res) {
   cout << i << ' ';
  }
  cout << '\n';
 }
}