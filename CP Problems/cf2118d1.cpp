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

bool dfs(ll cur_light, ll cur_second, set<vector<ll> >& seen, bool forward, ll n, ll k, vector<ll>& delays, vector<ll>& positions) {
  // seen: {cur_light, cur_second, forward}
  cur_second %= k;
  if (cur_light < 0) cur_light += n;
  if (cur_second == delays[cur_light]) {
    forward = (!forward);
  }
  
  if (cur_light == n - 1 && forward) return true;
  if (cur_light == 0 && !forward) return true;
  // if cycle, return false

  if (seen.count({cur_light, cur_second, forward})) {
    // cout << "seeing again: " << cur_light << "," << cur_second << forward << endl;
    return false;
  }
  seen.insert({cur_light, cur_second, forward});

  // cout << "currently at " << cur_light << " with time " << cur_second << " and moving forward=" << forward << '\n';
  // cout << "size of positions is " << positions.size() << endl;
  if (forward) {
    // need to check this carefully
    ll edge_length = positions[cur_light + 1] - positions[cur_light];
    assert(cur_light + 1 < positions.size());
    return dfs(cur_light + 1, cur_second + edge_length, seen, forward, n, k, delays, positions);
  }

  // going backwards
  // cout << "backwards???" << endl;
  // need to check this carefully
  ll edge_length = positions[cur_light] - positions[cur_light - 1];
  assert(cur_light - 1 >= 0);
  return dfs(cur_light - 1, cur_second + edge_length, seen, forward, n, k, delays, positions);
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 ll t;
 cin >> t;
 while (t--) {
  ll n, k;
  cin >> n >> k;
  vector<ll> positions(n);
  vector<ll> delays(n);
  // n: number of vertices in the graph
  // k: the mod we're working in
  // i connects to i + 1 in the grpah
  for (ll i = 0; i < n; i++) {
    cin >> positions[i];
  }

  for (ll i = 0; i < n; i++) {
    cin >> delays[i];
  }

  ll q;
  cin >> q;
  for (ll i = 0; i < q; i++) {
    ll a;
    cin >> a;
    // can optimize here
     // find nearest light
    // for (int i : positions) cout << i << " ";
    // cout << endl;
    auto iter = lower_bound(positions.begin(), positions.end(), a);
    // cout << "neraest right is " << *iter << endl;
    if (iter == positions.end()) {
      cout << "YES\n";
      continue;
    }
    
    ll nearest_right_light = std::distance(positions.begin(), iter);
    // cout << "nearest right light is " << nearest_right_light << endl;
    set<vector<ll> > seen;
    bool ans = dfs(nearest_right_light, positions[nearest_right_light] - a, seen, true, n, k, delays, positions);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
 }
 return 0;
}