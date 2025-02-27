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
  vector<int> rev_arr(arr.size());
  for (int i = 0; i < arr.size(); i++) {
    // given a number i, where is i located in arr
    rev_arr[arr[i]] = i;
  }

  vector<bool> seen(arr.size(), false);
  int result = 0;
  for (int i = 0; i < arr.size(); i++) {
    int cycle_length = 0;
    int current_index = i;
    // 2,1,0
    while (!seen[current_index]) {
      seen[current_index] = true;
      current_index = rev_arr[current_index];
      cycle_length++;
    }

    result += (cycle_length - 1) / 2;
  }

  return result;
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    arr.push_back(x);
  }

  cout << solve(arr, arr.size()) << '\n';
 }
 return 0;
}