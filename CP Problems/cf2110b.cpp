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
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  stack<int> st;
  st.push(0);
  bool first_type = false;
  for (int i = 1; i < s.size(); i++) {
    if (i == s.size() - 1 && st.top() == 0) first_type = true;
    if (s[i] == ')') st.pop();
    else st.push(i);
  }

  if (first_type) cout << "NO\n";
  else cout << "YES\n";
 }
 return 0;
}