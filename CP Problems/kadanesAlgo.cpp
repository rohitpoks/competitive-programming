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


int main() {
 long n;
 cin >> n;
 long cur = -1000000001;
 long res = -1000000001;
 for (long i = 0; i < n; i++) {
  long a;
  cin >> a;
  cur = max(cur + a, a);
  res = max(cur, res);
 }
 cout << res;
 return 0;
}