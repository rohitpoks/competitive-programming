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
#include <stack>
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
  int m;
  cin >> m;
  
  vector<int> cats(n+5, 0);
  vector<int> right(n+5, -1);
  vector<ll> dp(n+5, 0);
  vector<vector<int> > rightmost(n+5);
  vector<int> endsHere(n+5, 0);
  
  // pow(10,5)
  for (int i = 0; i < m; i++) {
   int a;
   int b;
   cin >> a >> b;
   cats[a] += 1;
   cats[b + 1] -= 1;
   // add rightmost+1
   rightmost[a].push_back(b+1);
   endsHere[b+1]++;
  }
  // given an index, how many cats present at this indedx
  for (int i = 1; i <= n + 1; i++) {
   cats[i] += cats[i-1];
  }
  multiset<int> active_rightmost;
  // pow(10,5) * 5
  ll res = 0;
  for (int i = n + 1;  i >= 0; i--) {
   if (endsHere[i] > 0) {
    for (int k = 0; k < endsHere[i]; k++) {
     active_rightmost.insert(i);
    }    
   }
   dp[i] = dp[i+1];
   if (!active_rightmost.empty()) dp[i] = max(cats[i] + dp[*
   (--active_rightmost.end())], dp[i+1]);
   res = max(res, dp[i]);
   for (int k : rightmost[i]) {    
    auto temp = active_rightmost.find(k);
    if (temp != active_rightmost.end()) active_rightmost.erase(temp);
   }
  }
  cout << res << '\n';
 }
 return 0;
}