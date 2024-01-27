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
 int n; int m;

 cin >> n >> m;
 vector<vector<int> > jobs(m+1);
 priority_queue<int> pq;
 for (int i = 0; i < n; i++) {
  int d; int r;
  cin >> d >> r;
  if (d > m) continue;
  jobs[d].push_back(r);
  // first reward, next time
  
 }
 long long res = 0;
 for (int i = 1; i <= m; i++) {
  for (int job: jobs[i]) {
   // all jobs that expire at or after day 1
   pq.push(job);
  }
  
  if (!pq.empty()) {
   res += pq.top();
   pq.pop();
  }

 }
 cout << res;
return 0;

}