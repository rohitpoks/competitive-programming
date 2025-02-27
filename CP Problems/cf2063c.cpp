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

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<set<int> > tree(n);
  int number_of_connected_components = 1;
  // given a vertex i, indegree_count[i] -> # of incoming edges at vertex i
  vector<int> indegree_count(n, 0);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    tree[u].insert(v);
    tree[v].insert(u);
    indegree_count[u]++;
    indegree_count[v]++;
  }

  // start removal of nodes
  for (int l = 0; l < 2; l++) {
    int highest = 0;
    for (int u = 0; u < n; u++) {
      // cout << "indegree count of " << u << " is " << indegree_count[u] << endl;
      highest = max(highest, indegree_count[u]);
    }

    set<int> nodes_with_highest;
    for (int i = 0; i < n; i++) {
      if (highest == indegree_count[i]) {
        nodes_with_highest.insert(i);
        // cout << "inserted " << i << '\n';
      }
    }

    int best_candidate = -1;
    int best_candidate_score = INT_MAX;
    for (int i : nodes_with_highest) {
      int current_node_score = 0;
      for (int n : tree[i]) {
        // cout << i << " is neighbors with " << n << endl;
        if (nodes_with_highest.count(n)) current_node_score++;
      }

      if (current_node_score < best_candidate_score) {
        // cout << "updating current node score to " << current_node_score << " for candidate " << i << endl;
        best_candidate_score = current_node_score;
        best_candidate = i;
      }
    }
    

    // remove best_candidate from the tree
    // cout << "best candidate is " << best_candidate << endl;
    number_of_connected_components += indegree_count[best_candidate] - 1;
    for (int n : tree[best_candidate]) {
      indegree_count[n]--;
    }

    // cout << "removed " << best_candidate << '\n';
    tree[best_candidate] = {};
    
    indegree_count[best_candidate] = 0;
  }

  cout << number_of_connected_components << '\n';
 }
}