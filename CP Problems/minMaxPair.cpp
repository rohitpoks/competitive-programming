#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>

using ll = long long;
using namespace std;

int main() {
 int n;
 cin >> n;
 vector<int> arr(n);
 vector<bool> match(n, false);
 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  a--;
  arr[i] = a;
  if (arr[i] == i) match[i] = true;
 }
 long long ans = 0;
 for (int i = 0; i < arr.size(); i++) {
  if (match[i]) {
   ans++;
  }

 }

 ans = (ans * (ans-1))/2;
 int addTo =0;
 for (int i = 0; i < match.size(); i++) {
  if (arr[i] != i && arr[arr[i]] == i) {
   addTo++;
  }
 }
 ans += (addTo)/2;
 cout << ans;
}