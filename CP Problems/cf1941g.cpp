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
 cin.tie(NULL);
 int z;
 cin >> z;
 while (z--) {
  int n, m;
  cin >> n >> m;
  map<int, vector<int> > a;
  map<int, vector<int> > b;
  for (int i = 0; i < m; i++) {
   int x, y, z;
   cin >> x >> y >> z;
   a[x].push_back(z);
   a[y].push_back(z);
   b[z].push_back(x);
   b[z].push_back(y);
  }
  queue<int> q;
  set<int> visited_a;
  set<int> visited_b;
  int s,e;
  cin >> s >> e;
  q.push(s);
  visited_a.insert(s);
  int dist = 0;
  int ans = -1;
  while (!q.empty()) {
   int s = q.size();
   if (ans != -1) break;
   for (int i = 0; i < s; i++) {
    int next = q.front();
    // cout << "next is " << next << " and dist is " << dist << endl;
    q.pop();
    if (next == e && dist % 2 == 0) {
     ans = dist;     
    } 
    if (dist % 2 == 0) {
     for (int j : a[next]) {
      if (visited_b.find(j) == visited_b.end()) {
       q.push(j);
       visited_b.insert(j);
      } 
     }
    } else {
     for (int j : b[next]) {
      if (visited_a.find(j) == visited_a.end()) {
       q.push(j);
       visited_a.insert(j);
      }
     }     
    }
   }
   dist++;
  }
  cout << ans / 2 << '\n';
 }
 return 0;

}