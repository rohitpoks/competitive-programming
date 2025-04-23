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
#include <cassert>

using ll = long long;
using namespace std;

// idea:
// a[i][j] -> number of paths of length 1 from vertex i to vertex j
// (a * a)[i][j] -> a[i][1] * a[1][j] + a[i][2] * a[2][j] + ... + a[i][n] * a[n][j]
// -> (number of length-1 paths from i to 1 and length 1 paths from 1 to j) + (number of length 1 paths from i to 2 and from 2 to j)...
// -> number of length 2 paths from i to j!

vector<vector<ll> > add_matrices(vector<vector<ll> >& m1, vector<vector<ll> >& m2, ll MOD = 1e9 + 7) {
  assert(m1.size() == m2.size() && m1[0].size() == m2[0].size());
  vector<vector<ll> > res(m1.size(), vector<ll>(m1.size(), 0));
  for (int i = 0; i < m1.size(); i++) {
    for (int j = 0; j < m1[0].size(); j++) {
      res[i][j] = m1[i][j] + m2[i][j];
      res[i][j] %= MOD;
    }
  }

  return res;
}

void print_matrix(vector<vector<ll> >& m1) {
  for (const auto& a : m1) {
    for (int j : a) {
      cout << j << " ";
    }

    cout << endl;
  }
}

vector<vector<ll> > mul(vector<vector<ll> >& m1, vector<vector<ll> >& m2, ll MOD = 1e9 + 7) {
  // size: a1 x b1 * b1 * c1
  // res has a1 rows and c1 cols
  vector<vector<ll> > res(m1.size(), vector<ll>(m2.size(), 0));
  for (int i = 0; i < m1.size(); i++) {
    for (int j = 0; j < m2.size(); j++) {
      // find ab[i][j] -> dot product of a's ith row and b's jth col
      for (int k = 0; k < m1[0].size(); k++) {
        res[i][j] += (m1[i][k] * m2[k][j]);
        res[i][j] %= MOD;
      }
    }
  }

  return res;
}
 
int main() {
 ios_base::sync_with_stdio(false);
 int n;
 ll k;
 cin >> n >> k;
 vector<vector<ll> > adj(n, vector<ll>(n, 0));
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < n; j++) {
    int n;
    cin >> n;
    adj[i][j] = n;
  }
 }

 vector<vector<ll> > res(n, vector<ll>(n, 0));
 for (int i = 0; i < n; i++) res[i][i] = 1;
 while (k > 0) {
  bool should_add = (k & 1);
  k /= 2;
  if (should_add) {
    res = mul(adj, res);
  }

  adj = mul(adj, adj);
 }

 ll output = 0;
 for (int i = 0; i < n; i++) {
  for (int j : res[i]) {
    output += j;
    output %= ((ll) 1e9 + 7);
  }
 }

 cout << output;
 return 0;
}