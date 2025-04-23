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
bool is_balanced(map<char, int>& count) {
  return (count['L'] == count['I']) && (count['L'] == count['T']);
}

void update_s(string& s, char c, vector<int>& res) {
  // insert c in s
  for (int i = 1; i <= s.size() - 1; i++) {
    cout << "trying to insert " << c << " in " << i << endl;
    // new character at index i
    if ((s[i] != c) && (s[i-1] != c) && (s[i] != s[i-1])) {
      string rep = s.substr(0, i);
      rep.push_back(c);
      rep += s.substr(i);
      s = rep;
      res.push_back(i);
      return;
    }
  }

  assert(1 != 1);
}

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

  map<char, int> counts;
  vector<int> res;
  counts['L'] = 0;
  counts['I'] = 0;
  counts['T'] = 0;

  for (int i = 0; i < n; i++) {
    counts[s[i]]++;
  }

  if (!(counts['L'] + counts['I']) || !(counts['I'] + counts['T']) || !(counts['I'] + counts['L'])) {
    cout << -1 << '\n';
    continue;
  }
  // pq by default is: max heap
  priority_queue<pair<int, char>, vector<pair<int, char> >, greater<pair<int, char> > > pq;
  for (auto& p : counts) {
    pq.push({p.second, p.first});
  }

  // get the smallest item
  while (!is_balanced(counts)) {
    auto item_to_insert = pq.top();
    item_to_insert.first++;
    counts[item_to_insert.second]++;
    pq.pop();
    pq.push(item_to_insert);
    update_s(s, item_to_insert.second, res);
  }

  cout << res.size() << '\n';
  for (int i : res) {
    cout << i << '\n';
  }

  // debug
  // cout << s << endl;
  // end debug
 }
 return 0;
}