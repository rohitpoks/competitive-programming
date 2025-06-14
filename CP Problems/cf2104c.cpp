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
#include <cassert>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<int> alice;
  set<int> bob;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      alice.insert(i+1);
    } else {
      bob.insert(i+1);
    }
  }

  bool alice_wins = false;
  for (int i : alice) {
    // cout << "next alice card is " << i << endl;
    if (i == 1) {
      if (*(bob.begin()) == n) {
        alice_wins = true;
        // cout << "here" << endl;
      }
    } else if (i == n) {
      if (*(bob.begin()) != 1) {
        // cout << "here here" << endl;
        alice_wins = true;
      }
    } else {
      // alice played something that's neither 1 or n
      if ((*(--bob.end())) < i) {
        // cout << "here here here" << endl;
        alice_wins = true;
      }
    }
  }

  if (alice_wins) cout << "Alice";
  else cout << "Bob";
  cout << '\n';
 }
 return 0;
}