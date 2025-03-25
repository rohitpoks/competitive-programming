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


struct pt {
  double x, y;
};

int orientation(pt a, pt b, pt c) {
  // orientation of the cross product of the vector (b - a) and the vector (c - b)
  double res = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  if (res > 0) return 1;
  else if (res < 0) return -1;
  return 0;
}

int cw(pt a, pt b, pt c, bool include_collinear = false) {
  int o = orientation(a, b, c);
  return (o > 0 || (include_collinear && o == 0));
}

int ccw(pt a, pt b, pt c, bool include_collinear = false) {
  int o = orientation(a, b, c);
  return (o < 0 || (include_collinear && o == 0));
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1) return;

    // sort the points by x coordinate first (left-most first) and y coordinate next (bottom-most first)
    sort(a.begin(), a.end(), [](pt a, pt b) {
      return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });

    pt p1 = a[0];
    pt p2 = a.back();
    vector<pt> up, down;
    down.push_back(p1);
    if (a.size() > 1) down.push_back(a[1]);
    // p1 and p2 will be in the hull
    for (int i = 2; i < a.size(); i++) {
      while (cw(down[down.size() - 2], down[down.size() - 1], a[i], include_collinear)) {
        down.pop_back();
      }

      down.push_back(a[i]);
    }

    for (const auto& p : down) {
      cout << p.x << "," << p.y << endl;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  vector<pt> a = {{0, 0}, {1, 1}, {2, -1}, {3,1}, {2.5, 1.5}};
  convex_hull(a, false);
  cout << ccw({0, 0}, {1, 1}, {2, -1});
  return 0;
}