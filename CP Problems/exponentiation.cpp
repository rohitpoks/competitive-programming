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

int fast_exp(int a, int n, int p) {
  // calculate a^n mod p
  ll current_pow = a;
  ll result = 1;
  while (n != 0) {
    if (n % 2 == 1) {
      result *= current_pow;
      result %= p;
    }

    current_pow *= current_pow;
    current_pow %= p;
    n /= 2;
  }

  return result;
}
int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int a, b;
  cin >> a >> b;
  cout << fast_exp(a, b, 1e9 + 7) << '\n';
 }
 return 0;
}