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
 int z;
 cin >> z;
 // greedily subtract and check
 for (int q = 0; q < z; q++) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }

  for (int j = 0; j < n; j++) {
   if (arr[j] <= 0) continue;
   if (j + 2 <= n - 1) {
    arr[j + 1] -= (arr[j] * 2);
    arr[j + 2] -= arr[j];
    arr[j] = 0;
   }
  }
  bool res = true;
  for (int i = 0; i < n; i++) {
   if (arr[i] != 0) {
    res = false;
   }
  }
  if (res) cout << "yes" << '\n';
  else cout << "no" << '\n';
 }
 return 0;
}