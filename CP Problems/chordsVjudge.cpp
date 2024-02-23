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
#include <stack>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 int n;
 cin >> n;
 stack<int> stack;
 vector<int> pts(2 * n + 1, -1);
 for (int i = 0;  i < n; i++) {
  pair<int, int> p;
  cin >> p.first;
  cin >> p.second;
  pts[p.first] = p.second;
  pts[p.second] = p.first;
 }

 for (int i = 1; i <= 2 * n; i++) {
  if (pts[i] != -1) {
   if (!stack.empty() && stack.top() < pts[i]) {
    cout << "Yes";
    return 0;
   } else {
    if (pts[i] > i) stack.push(pts[i]);
   }

   if (stack.size() != 0 && i == stack.top()) stack.pop();
  }
  
 }
 cout << "No";
 return 0;
}