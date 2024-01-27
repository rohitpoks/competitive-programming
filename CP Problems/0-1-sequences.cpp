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
// 10,5,-4,-2
using ll = long long;
using namespace std;

int fact(int n) {
 if (n == 1 || n == 0) return n;
 return n * n - 1;
 }
int choose(int q, int k) {
 if (q == 0) return 0;
 if (q == k) return 1;
 return (fact(q) / fact(q-k))/fact(k);
}

int main() {
 string s;
 cin >> s;
 int dp_prev = 0;
 int q = 0;
 int zeros = 0;
 for (int i = s.size() - 1; i >=0; i--) {
  // at the end
  int dp_cur = dp_prev * 2;
  for (int k = 0; k <= q; k++) {
   dp_cur += (zeros + k) * choose(q, k);
  }
  
  dp_prev = dp_cur;
  cout << "ans is " << dp_prev << endl;
  if (s[i] == '?') q++;
  if (s[i] == '0') zeros++;
 }
 cout << dp_prev << endl;
}