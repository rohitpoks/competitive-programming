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

bool check(vector<char>& state) {
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 int tn = 1;
 while (t--) {
  string s;
  cin >> s;
  vector<char> state(s.size() + 5, 'e');
  // states: s, n, e
  int cur_p = 0;
  state[0] = 's';
  state[1] = 's';
  set<int> s_indices;
  set<int> n_indices;
  s_indices.insert(0);
  s_indices.insert(1);
  bool violated = false;
  int cur_num_elements = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+') {
      cur_num_elements++;
      cur_p++;
    } else if (s[i] == '-') {
      cur_num_elements--;
      if (state[cur_p] == 's') {
        s_indices.erase(cur_p);
        s_indices.insert(cur_p - 1);
        state[cur_p-1] = 's';
      } else {
        n_indices.erase(cur_p);
      }

      state[cur_p] = 'e';
      cur_p--;
    } else if (s[i] == '1') {
      if (state[cur_p] == 'n') violated = true;
      state[cur_p] = 's';
      s_indices.insert(cur_p);
    } else {
      if (cur_num_elements < 2) violated = true;
      if (state[cur_p] == 's') violated = true;
      state[cur_p] = 'n';
      n_indices.insert(cur_p);
    }

    // after each operation, check whether the smallest unsorted array is a prefix of the largest sorted array
    if (n_indices.size() && (*(--s_indices.end()) > *(n_indices.begin()))) violated = true;
  }

  if (!violated) cout << "YES\n";
  else cout << "NO\n";
  tn++;
 }
 
 return 0;
}