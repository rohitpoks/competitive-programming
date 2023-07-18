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


int main() {
 int n;
 cin >> n;
 vector<pair<int, int> > times;
 for (int i = 0; i < n; i++) {
  pair<int, int> start;
  pair<int, int> end;
  int a;
  int b;
  cin >> a >> b;
  start.first = a;
  start.second = 0;
  end.first = b;
  end.second = 1;
  times.push_back(start);
  times.push_back(end);
 }

 sort(times.begin(), times.end());
 int count = 0;
 int res = 0;
 for (pair<int, int> i : times) {
  if (i.second == 0) {
   count++;
  }
  else count--;
  res = max(res, count);
 }
 cout << res;
 return 0;
}