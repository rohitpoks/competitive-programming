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
 for (int q = 0; q < z; q++) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int res = 0;
  for (int k = 0; k <= n-3; k++) {
   if (s.substr(k, 3) == "map") res++;
   if (s.substr(k,3) == "pie") res++;
   if (k <= n-5 && s.substr(k,5) == "mapie") res--;
  }

  cout << res << '\n';

 }
 return 0;
}