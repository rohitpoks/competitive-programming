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
#include <climits>

using ll = long long;
using namespace std;

long double get_score(int i, int n) {
 return abs((long double) n/2-i);
}

int main() {
 ios_base::sync_with_stdio(false);
 int z;
 cin >> z;
 while (z--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> left_count(n + 1, 0);
  for (int i = 1; i <= n; i++) {
   if (s[i-1] == '0') left_count[i] = left_count[i-1] + 1;
   else (left_count[i] = left_count[i-1]);
   // cout << "left count at " << i << ": " << left_count[i] << endl;
  }
  long double best_score = INT_MAX;
  int best_index = 0;
  for (int i = 0; i <= n; i++) {
   if ((i/2 + i%2 <= left_count[i]) && (n-i-(left_count[n] - left_count[i]) >= ((n-i)/ 2 + (n-i) % 2))) {
    // cout << "here at " << i << endl;
    long double score = get_score(i, n);
    // cout << "score is " << score << endl;
    if (score < best_score) {
     best_index = i;
     best_score = score;
    }
   }
   // cout << "---" << endl;
  }
  
  cout << best_index <<  '\n';
 }
 return 0;
}