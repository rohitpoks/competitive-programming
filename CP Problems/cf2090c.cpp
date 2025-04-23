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

void increase(int& X, int& Y) {
  X += 3;
  Y -= 3;
  if (Y < 0) {
    Y += 3;
    int temp = X;
    X = Y;
    Y = temp;
  }
}

void solve(vector<int>& guests) {
  int X = 1;
  int Y = 1;
  // [dist, x, y]
  // pq: all free positions at occupied tables
  priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
  vector<pair<int, int> > res;
  for (int i = 0; i < guests.size(); i++) {
    if (!guests[i]) {
      // type 1
      res.push_back({X, Y});
      // since new table occupied, add its free cells and distances
      pq.push({X + Y + 1, X, Y + 1});
      pq.push({X + Y + 1, X + 1, Y});
      pq.push({X + Y + 4, X + 1, Y + 1});
      // increase X, Y
      increase(X, Y);
    } else {
      // type 0
      // get next from pq;
      vector<int> next = {INT_MAX, INT_MAX, INT_MAX};
      if (!pq.empty()) {
        next = pq.top();
      }

      vector<int> check = {X + Y, X, Y};
      if (check < next) {
        next = check;
      }

      res.push_back({next[1], next[2]});
      if (!pq.empty() && next == pq.top()) {
        // picked some table that was occupied
        pq.pop();
      } else {
        // picked a new table, so add its neighbors to PQ
        pq.push({X + Y + 1, X, Y + 1});
        pq.push({X + Y + 1, X + 1, Y});
        pq.push({X + Y + 4, X + 1, Y + 1});
        increase(X, Y);
      }
    }
  }

  for (const auto& n : res) {
    cout << n.first << ' ' << n.second << '\n';
  }
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> guests(n);
  for (int i = 0; i < n; i++) {
    cin >> guests[i];
  }

  solve(guests);
 }
 return 0;
}