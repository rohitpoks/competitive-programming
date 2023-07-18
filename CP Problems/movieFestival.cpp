#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
 if (p1.second == p2.second) return p1.first < p2.first;
 return p1.second < p2.second;
}

int main() {
 int n;
 cin >> n;
 vector<pair<int, int> > times;
 for (int i = 0; i < n; i++) {
  pair<int, int> cur;
  cin >> cur.first;
  cin >> cur.second;
  times.push_back(cur);
 }


 sort(times.begin(), times.end(), compare);
 int cur_end = -1;
 int res = 0;
 for (pair<int, int> i : times) {
  if (i.first >= cur_end) {
   res++;
   cur_end = max(cur_end, i.second);
  }
 }
 cout << res;
 return 0;
}