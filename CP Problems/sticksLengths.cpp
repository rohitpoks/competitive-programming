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
using namespace std;

int main()
{
 vector<long> sticks;
 int n;
 cin >> n;

 for (int i = 0;  i < n; i++) {
  long a;
  cin >> a;

  sticks.push_back(a);
 }

 sort(sticks.begin(), sticks.end());

 long md = (n + 1) / 2 - 1;

 long long res = 0;
 for (long i : sticks) {
  res += abs(i - sticks[md]);
 }
 cout << res;

 return 0;
}