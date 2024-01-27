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

int main() {
 int n;
 int k;

 cin >> n >> k;
 string s;
 cin >> s;
 int h = 0;
 for (int i = 0; i < s.size()-1; i++) {
  if (s[i] == s[i+1]) {
   h++;
  }
 }

 cout << min(h + 2 * k, n-1);
}