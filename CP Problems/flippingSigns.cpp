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
 vector<int> arr;
 ll sum = 0;
 int count = 0;
 bool even = false;
 int mini = INT_MAX;
 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  sum+=abs(a);
  arr.push_back(a);
  if (a < 0) count++;
  if (a == 0) even = true;
   mini = min(mini, abs(a));
 }
 // cout << count << endl;
 // cout << sum << endl;
 // cout << mini << endl;
 if (count % 2 == 0) even = true;
 if (even) cout << sum; 
 else cout << sum - 2 * abs(mini);
 return 0;
}