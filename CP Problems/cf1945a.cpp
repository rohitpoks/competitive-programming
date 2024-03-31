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
 while (z--) {
  ll a, b, c;
  cin >> a >> b >> c;
  if ((b % 3 == 1 && c <= 1) || (b % 3 == 2 && c == 0)) {
   cout << -1 << '\n';
   continue;
  }
  int extra = ((b + c) % 3 == 0) ? 0 : 1;
  cout << (a + (b + c)/3 + extra) << '\n';

 }
 
 return 0;
}