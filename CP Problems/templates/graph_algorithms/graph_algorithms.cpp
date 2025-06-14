/* 

BFS to find shortest even/odd length paths
queue<ll> q;
set<ll> seen_even;
set<ll> seen_odd;
seen_even.insert(1);
q.push(1);
vector<vector<ll> > dist(n + 1, vector<ll>(2, LLONG_MAX));
dist[1][0] = 0;
ll d = 0;
while (!q.empty()) {
  ll s = q.size();
  for (ll i = 0; i < s; i++) {
    ll next = q.front();
    q.pop();
    if (dist[next][d % 2] == LLONG_MAX) dist[next][d%2] = d;
    for (ll n : g[next]) {
      if (dist[next][0] != LLONG_MAX) {
        dist[n][1] = min(dist[n][1], dist[next][0] + 1);
      }

      if (dist[next][1] != LLONG_MAX) {
        dist[n][0] = min(dist[n][0], dist[next][1] + 1);
      }

      if (!seen_even.count(n) && dist[n][0] != LLONG_MAX) {
        seen_even.insert(n);
        q.push(n);
      }

      if (!seen_odd.count(n) && dist[n][1] != LLONG_MAX) {
        seen_odd.insert(n);
        q.push(n);
      }
    }
  }

  d++;
}
*/
