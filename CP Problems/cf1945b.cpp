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
  ll a; ll b; ll c;
  cin >> a >> b >> c;
  cout << (c/a) + (c/b) + 2 << '\n';
 }
 

 return 0;
}