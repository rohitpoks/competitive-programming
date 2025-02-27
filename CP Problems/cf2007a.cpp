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
   cin >> t;
   while (t--) {
      int l;
      int r;
      cin >> l >> r;   
      int first_odd = (l % 2 == 1) ? l : l + 1;
      int last_num = r;
      cout << (last_num - first_odd + 2)/4 << '\n';
 }
 
 return 0;
}