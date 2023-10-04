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
#include <climits>
using ll = long long;
using namespace std;

int main()
{

 set<pair<int, int> > set;
 int n;

 cin >> n;
 vector<int> cubes;
 for (int i = 0; i < n; i++)
 {
  int temp;
  cin >> temp;
  cubes.push_back(temp);
 }
 set.insert({cubes[0], 0});
 for (int i = 1; i < n; i++) {
  int cur = cubes[i];
  auto cur_pair = set.upper_bound({cubes[i], INT_MAX});
  if (cur_pair == set.end()) {
   set.insert({cur, i});
  } else {
   set.erase(*cur_pair);
   set.insert({cur, i});
  }
  // 1 6 6 7 8, 6
 }
 cout << set.size() << endl;
 return 0;
}
