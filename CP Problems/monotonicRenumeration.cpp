#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>
#include <map>

using ll = long long;
using namespace std;


ll pow2(int n) {
    ll res = 1;
    ll base = 2;
    ll mod = 998244353;
    while (n > 0) {
        if (n & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
 ios_base::sync_with_stdio(false);
 int n;
 cin >> n;
 vector<int> a(n);
 map<int, int> last;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }

 for (int i = 0; i < a.size(); i++) {
  last[a[i]] = i;
 }
 int curLast = -1;
 int res = 0;
 for (int i = 0; i < a.size(); i++) {
  
  curLast = max(curLast, last[a[i]]);
  // cout << "cur last is " << curLast << endl;
  if (curLast <= i) res++;
  
 }

 cout << pow2(res-1);
 return 0;
}