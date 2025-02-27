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

int solve(vector<int>& arr, int n) {
  // start from the inside
  // greedily place the best option so far
  vector<int> res(n);
  int l = arr.size() / 2 - 1;
  int r = arr.size() / 2 + 1;
  if (arr.size() % 2 == 0) r--;

  while (l >= 0 && r < arr.size()) {
    // decide if wanna swap or not
    if ((arr[l] == arr[l+1]) || (arr[r] == arr[r-1])) {
      int temp = arr[l];
      arr[l] = arr[r];
      arr[r] = temp;
    }
    // cout << l << "," << r << endl;
    l--;
    r++;
  }

  int score = 0;
  for (int i = 0; i < arr.size() - 1; i++) {
    // cout << arr[i] << ",";
    if (arr[i] == arr[i + 1]) score++;
  }
  // cout << arr.back() << endl;

  return score;
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << solve(arr, n) << '\n';
 }
 return 0;
}