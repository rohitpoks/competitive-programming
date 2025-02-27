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
using State = pair<ll, pair<int, int> >;

vector<ll> modifiedDijkstras(int n, int m, int h, vector<vector<pair<int, int>>>& adj, int start, vector<bool>& verticesContainingHorse) {
    priority_queue<State, vector<State>, greater<State>> pq;  // Min-heap based on distance
    vector<vector<ll>> shortestPathsToStart(n + 1, vector<ll>(2, LLONG_MAX));

    // Initialize the start vertex
    int horseState = verticesContainingHorse[start] ? 1 : 0;
    pq.push({0, {start, horseState}});
    shortestPathsToStart[start][horseState] = 0;

    while (!pq.empty()) {
        auto [currDist, uState] = pq.top();  // current distance and (vertex, horseState)
        auto [u, hasHorse] = uState;
        pq.pop();

        // If the current distance is already larger, skip it
        if (currDist > shortestPathsToStart[u][hasHorse]) continue;

        // Explore neighbors
        for (auto& [v, weight] : adj[u]) {
            bool newHorseState = hasHorse || verticesContainingHorse[v];
            ll newDist = currDist + (hasHorse ? weight / 2 : weight);

            // Relaxation step
            if (newDist < shortestPathsToStart[v][newHorseState]) {
                shortestPathsToStart[v][newHorseState] = newDist;
                pq.push({newDist, {v, newHorseState}});
            }
        }
    }

    // Collect the result: take the minimum of the two possible states for each vertex
    vector<ll> res(n + 1);
    for (int i = 1; i <= n; ++i) {
        res[i] = min(shortestPathsToStart[i][0], shortestPathsToStart[i][1]);
    }

    return res;
}

void solve(int n, int m, int h, vector<vector<pair<int, int> > >& adj, int start1, int start2, vector<bool>& verticesContainingHorse) {
  vector<ll> shortestPathsToStart1 = modifiedDijkstras(n, m, h, adj, start1, verticesContainingHorse);
  vector<ll> shortestPathsToStart2 = modifiedDijkstras(n, m, h, adj, start2, verticesContainingHorse);

  ll res = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    ll currentVertexTime = max(shortestPathsToStart1[i], shortestPathsToStart2[i]);
    // cout << "to reach vertex " << i << " from " << 1 << " would take " << shortestPathsToStart1[i] << endl;
    res = min(res, currentVertexTime);
  }

  if (res == LLONG_MAX) cout << "-1" << '\n';
  else cout << res << '\n';
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n, m, h;
  cin >> n >> m >> h;
  vector<bool> hasHorse(n + 1, false);
  for (int i = 0; i < h; i++) {
    int k;
    cin >> k;
    hasHorse[k] = true;
  }

  vector<vector<pair<int, int> > > adj(n + 1);
  for (int j = 0; j < m; j++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }  

  solve(n, m, h, adj, 1, n, hasHorse);
 }

 return 0;
}
