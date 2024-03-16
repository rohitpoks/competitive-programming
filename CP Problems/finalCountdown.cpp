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
#include <stack>
#include <climits>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 int z;
 cin >> z;
 for (int q = 0; q < z; q++) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll res = 0;
  vector<int> leadingZeros;
  // sum up all digits
  for (int i = 0; i < s.size(); i++) {
   char c = s[i];
   res += (c-'0');
  }
  int cur_rem = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
   leadingZeros.push_back(res % 10);
   // cout << "res is " << res << endl;   
   int temp = res / 10;
   res += temp;
   res -= cur_rem;
   cur_rem = temp;
   res -= (s[i] - '0');   
  }
  if (res > 0) leadingZeros.push_back(res);
  while (!leadingZeros.empty() && leadingZeros.back() == 0) {
   leadingZeros.pop_back();
  }
  while (!leadingZeros.empty()) {
   cout << leadingZeros.back();
   leadingZeros.pop_back();
  }
  cout << '\n';
 }
 return 0;
}