#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <cassert>

using ll = long long;
using uint = unsigned int;
using namespace std;

bool is_possible(vector<vector<pair<int, int> > >& graph, ll max_edge_weight, int n, vector<ll>& battery) {
  vector<vector< pair<int, int> > > copy(n);
  for (int i = 0; i < n; i++) {
    for (auto j : graph[i]) {
      if (j.second <= max_edge_weight) {
        copy[i].push_back(j);
      }
    }
  }

  // bfs sort on copy
  // {current vertex, battery}
  vector<ll> max_b(n, 0);
  max_b[0] = battery[0];
  for (int i = 0; i < n; i++) {
    for (auto [neighbor_vertex, weight] : copy[i]) {
      if (weight <= max_b[i]) {
        max_b[neighbor_vertex] = battery[neighbor_vertex] + max_b[i];
      }
    }
  }


  return max_b[n - 1] > 0;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int m, n;
  cin >> n >> m;
  vector<ll> battery(n);
  vector<vector<pair<int, int> > > graph(n);
  for (int i = 0; i < n; i++) {
    cin >> battery[i];
  }

  for (int i = 0; i < m; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    s--;
    t--;
    // u : {v, w}
    graph[s].push_back({t, w});
  }

  // priority_queue<pair<int, pair<ll, int> >, vector<pair<int, pair<ll, int> > >, greater<pair<int, pair<ll, int> > > > pq;
  // // priority_queue<vector<ll>, vector<vector<ll> >, greater<vector<ll> > > pq;
  // pq.push({0, {battery[0], 0}});
  // ll res = -1;
  // while (!pq.empty()) {
  //   auto next = pq.top();
  //   ll max_edge_so_far = next.first;
  //   ll total_battery_so_far = next.second.first;
  //   ll path_endpt = next.second.second;
  //   pq.pop();

  //   if (path_endpt == n - 1) {
  //     res = max_edge_so_far;
  //     break;
  //   }

  //   for (auto n : graph[path_endpt]) {
  //     auto [neighbor_vertex, neighbor_edge_weight] = n;
  //     if (neighbor_edge_weight <= total_battery_so_far) {
  //       pq.push({max(max_edge_so_far, (ll) neighbor_edge_weight), {total_battery_so_far + battery[neighbor_vertex], neighbor_vertex}});
  //     }
  //   }
  // }

  // cout << res << '\n';
  // // q: why does the SEEN logic not work? counterexample?
  // // seen logic: every time you remove a vertex from pq, mark it as seen
  // // problem with seen: you are not always exploring all possible paths
  // // when do you mark a vertex as seen? when you remove it from the priority queue. when you remove a vertex from the priority queue for the first time
  // // it's guaranteed to be the most optimal path. however, you might get to a vertex quickly with less battery, and then later, get to the same vertex with a higer battery but this time
  // // you might not explore some future vertices!


  // // Dijkstra's appraoch worst case: explore every single path from soure to destination, exponential time/space

  // attempt 2: b_search + dp

  ll l = 0;
  ll r = 1e9 + 1;
  while (r != l + 1) {
    ll max_edge_weight = (l + r) / 2;
    // if possible with max edge weight
    bool p = is_possible(graph, max_edge_weight, n, battery);
    if (p) {
      r = max_edge_weight;
    } else {
      l = max_edge_weight;
    }

  }

  if (is_possible(graph, r, n, battery)) cout << r << '\n';
  else cout << -1 << '\n';
 }
 return 0;
}