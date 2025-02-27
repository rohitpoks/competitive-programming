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


void generate_all(int num_quizzes, int num_days, int current_day, vector<int>& arr, vector<vector<int> >& res) {
  if (current_day > num_days) {
    res.push_back(arr);
    return;
  }

  for (int i = 0; i < num_quizzes; i++) {
    arr.push_back(i + 1);
    generate_all(num_quizzes, num_days, current_day + 1, arr, res);
    arr.pop_back();
  }
}

int main() {
 ios_base::sync_with_stdio(false);
 while (1) {
  int n, q, r, f;
  cin >> n >> q >> r >> f;
  // ignore newline after cin
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  vector<vector<int> > quizzesForStudent(n + 1);
  vector<set<int> > quizConflicts(q + 1);
  if (n == 0 && q == 0 && r == 0 && f == 0) break;

  for (int i = 0; i < n; i++) {
    string response;
    getline(cin, response);
    for (char c : response) {
      if (c == ' ') continue;
      quizzesForStudent[i].push_back(c - '1');
    }
  }

  for (const auto& quiz : quizzesForStudent) {
    for (int i : quiz) {
      for (int j : quiz) {
        quizConflicts[i].insert(j);
        quizConflicts[j].insert(i);
        // cout << "conflict:" << i << "," << j << '\n';
      }
    }
  }

  vector<int> temp;
  vector<vector<int> > allPerms;
  generate_all(f, q, 1, temp, allPerms);

  bool global_p = false;
  for (const auto& perm : allPerms) {
    bool possible = true;
    for (int i = 0; i < perm.size(); i++) {
      // quiz number i, scheduled for day perm[i]
      for (int j = 0; j < perm.size(); j++) {
        // perm[i] -> day on which quiz should be taken
        if (perm[i] != perm[j] || i == j) continue;
        if (quizConflicts[i].count(j)) {
          // cout << "found conflict in " << perm[i] + 1<< "," << perm[j] + 1 << endl;
          possible = false;
        } 
      }
    }

    if (possible) {
      global_p = true;
    }
  }

  if (global_p) cout << "YES" << '\n';
  else {
    cout << "NO" << '\n';
  }

 }
 return 0;
}