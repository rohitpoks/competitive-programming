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
#include <cassert>

using ll = long long;
using namespace std;

// return how many paths parent is a part of through this 'root'
int dfs(int root, vector<vector<int> >& tree, vector<int>& start, vector<int>& lca_1, vector<int>& lca_2, int p, vector<int>& res) {
  int r = 0;
  for (int c : tree[root]) {
    if (c != p) r += dfs(c, tree, start, lca_1, lca_2, root, res);
  }

  r += start[root];
  r -= lca_2[root];
  res[root] = r;
  return r - lca_1[root] - lca_2[root];
}

int ith_parent(int node, int i, vector<vector<int> >& tree, vector<vector<int> >& power_two_parent) {
  while (i > 0) {
    int lz = __builtin_clz(i);
    int next_parent_dist = 31 - lz;
    if (next_parent_dist >= power_two_parent[node].size()) return 0;
    node = power_two_parent[node][next_parent_dist];
    i -= (1 << next_parent_dist);
  }

  return node;
}

int have_same_parent(int a, int b, int i, vector<vector<int> >& power_two_parent, vector<vector<int> >& tree) {
  int ba = ith_parent(a, i, tree, power_two_parent);
  if (ba == ith_parent(b, i, tree, power_two_parent)) {
    return ba;
  }

  return 0;
}


int lca(int a, int b, vector<int>& level_of_node, vector<vector<int> >& tree, vector<vector<int> >& power_two_parent) {
  int la = level_of_node[a];
  int lb = level_of_node[b];
  // WLOG: assume a is placed lower on the tree (at a higher level) than b
  if (la < lb) {
    // swap a, b and la, lb if necessary
    int t = lb;
    lb = la;
    la = t;
    t = a;
    a = b;
    b = t;
  }

  // first, bring the nodes at the same level. b is lower in the tree, bring it up
  a = ith_parent(a, la - lb, tree, power_two_parent);

  if (a == b) {
    return a;
  }

  // consider binary lifting until you no longer can lift the nodes
  for (int i = 20; i >= 0; i--) {
    int power_i_parent_a = (i < power_two_parent[a].size() ? power_two_parent[a][i] : -1);
    int power_i_parent_b = (i < power_two_parent[b].size() ? power_two_parent[b][i] : -1);
    if (power_i_parent_a != power_i_parent_b) {
      a = power_i_parent_a;
      b = power_i_parent_b;
    }
  }

  return power_two_parent[a][0];
}




int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, queries;
 cin >> n >> queries;
 vector<vector<int> > tree(n + 1);
 for (int i  = 0; i < n - 1; i++) {
  int u, v;
  cin >> u >> v;
  tree[u].push_back(v);
  tree[v].push_back(u);
 }

 queue<pair<int, int> > q;
 vector<int> level_of_node(n + 1);
 vector<int> start(n + 1, 0);
 vector<int> lca_1(n + 1, 0);
 vector<int> lca_2(n + 1, 0);
 vector<vector<int> > power_two_parent(n + 1);
 // usage: power_two_parent[node][power] => boss of node at level 2 ^ power above node
 q.push({1, -1});
 int level = 0;
 level_of_node[1] = 0;
 while (!q.empty()) {
  int s = q.size();
  while (s--) {
    auto [n, p] = q.front();
    level_of_node[n] = level;
    q.pop();
    if (p != -1) {
      power_two_parent[n].push_back(p);
    }
    
    int cur_pow = 0;
    int original_parent = p;
    while (power_two_parent[p].size() > cur_pow && (p > -1)) {
      power_two_parent[n].push_back(power_two_parent[p][cur_pow]);
      p = power_two_parent[p][cur_pow];
      cur_pow++;
    }

    for (int ne : tree[n]) {
      if (ne != original_parent) {
        q.push({ne, n});
      }
    }
  }
  
  level++;
 }

 while (queries--) {
  int u, v;
  cin >> u >> v;
  int lowest_com_anc = lca(u, v, level_of_node, tree, power_two_parent);
  if (lowest_com_anc == u && lowest_com_anc == v) {
    start[u]++;
    lca_1[u]++;
  } else if (lowest_com_anc == u) {
    start[v]++;
    lca_1[u]++;
  } else if (lowest_com_anc == v) {
    start[u]++;
    lca_1[v]++;
  } else {
    start[u]++;
    start[v]++;
    lca_2[lowest_com_anc]++;
  }
 }

 vector<int> res(n + 1);
 dfs(1, tree, start, lca_1, lca_2, -1, res);
 for (int i = 1; i <= n; i++) cout << res[i] << ' ';
 return 0;
}