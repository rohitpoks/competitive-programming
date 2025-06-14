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
#include <stack>
#include <cassert>

using ll = long long;
using uint = unsigned int;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  string s;
  for (int i = 0; i < n - k; i++) {
    s.push_back('0');
  }

  for (int i = 0; i < k; i++) {
    s.push_back('1');
  }

  cout << s << '\n';
 }
 return 0;
}