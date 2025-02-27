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

void solve(int n, int d, int k, vector<vector<int>>& intervals) {
  int res = 0;
  map<int, int> countAtStartTime;
  map<int, int> countAtEndTime;
  for (auto& i : intervals) {
    if (!countAtStartTime.count(i[0])) {
      countAtStartTime[i[0]] = 0;
    }

    if (!countAtEndTime.count(i[1])) {
      countAtEndTime[i[1]] = 0;
    }

    countAtStartTime[i[0]]++;
    countAtEndTime[i[1]]++;
  }

  int windowCount = 0;
  for (int i = 1; i <= d; i++) {
    if (countAtStartTime.count(i)) {
      windowCount += countAtStartTime[i];
    }
  }

  int maxWindowCount = windowCount;
  int minWindowCount = windowCount;
  int maxStartIndex = 1;
  int minStartIndex = 1;
  for (int j = d + 1; j <= n; j++) {
    windowCount -= countAtEndTime[j - d];
    windowCount += countAtStartTime[j];
    if (windowCount > maxWindowCount) {
      maxWindowCount = windowCount;
      maxStartIndex = j - d + 1;
    }

    if (windowCount < minWindowCount) {
      minWindowCount = windowCount;
      minStartIndex = j - d + 1;
    }
  }

  cout << maxStartIndex << " "  << minStartIndex << '\n';
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n, d, k;
  cin >> n >> d >> k;
  vector<vector<int>> intervals;
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    intervals.push_back({l, r});
  }

  solve(n, d, k, intervals);
 }
}