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

bool is_set(int num, int b) {
  // b : msb 0, 1, 2, 3, ..., 29 lsb
  // when b = 0
  int act = 30 - b;
  int start = 1;
  for (int i = 1; i < act; i++) {
    start *= 2;
  }

  return start & num;
}

int msb(int x) {
  // return msb, with lsb being bit 29
  int start = 1;
  // what is lshift in c++?
  for (int i  = 1; i < 30; i++) {
    start = start * 2;
  }

  int cur_bit = 0;
  while (true) {
    // cout << "here inf loop" << endl;
    if (x & start) return cur_bit;
    cur_bit++;
    start = start / 2;
  }
}

vector<vector<int> > create_table(vector<int>& a) {
  vector<vector<int> > table(a.size(), vector<int>(30, INT_MAX));
  // table: 0 -> msb, 29 -> lsb
  // table[][] -> -1 implies can go all the way through, no larger number
  int n = a.size();
  for (int i = 0; i < 30; i++) {
    table[0][i] = -1;
  }

  for (int i  = 1; i < n; i++) {
    table[i][0] = table[i - 1][0];
    if (is_set(a[i - 1], 0)) {
      table[i][0] = i - 1;
    }
  }
  
  for (int idx = 1; idx < n; idx++) {
    for (int b = 1; b < 30; b++) {
      if (is_set(a[idx - 1], b)) {
        // cout << "at index " << idx << " and next element's bit " << b << " is set" << endl;
        table[idx][b] = idx - 1;
      } else {
        table[idx][b] = max(table[idx - 1][b], table[idx][b - 1]);
      }
    }
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < 30; j++) {
  //     cout << table[i][j] << ' ';
  //   }

  //   cout << endl;
  // }
  // 58: 111010
  return table;
}
int main() {
  // vector<ll> check = {10, 8, 6};
  // int c = 8;
  // int l = 0;
  // int r = check.size();
  // bsearch(l, r, check, c);
  // cout << r << endl;
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  vector<int> pxor(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    pxor[i] = arr[i];
    if (i == 0) {
      continue;
    }
    
    pxor[i] ^= pxor[i - 1];
  }

  vector<vector<int> > table = create_table(arr);

  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    int r = arr.size() - 1;
    int l = arr.size() - 1;
    // l : current number to compare to
    while (l != -1) {
      if (arr[l] > x) break;
      x = x ^ arr[l];
      // cout << "after xor is " << x << endl;
      // cout << "msb of " << x << " is " << msb(x) << endl;
      if (x == 0) {
        l--;
        break;
      }

      int prev_l = l;
      l = table[l][msb(x)];
      // pxor ?
      // need to pxor from l to prevl inclusive
      // l : index to go to
      // prev l : currently at index
      if (l - 1 >= 0) {
        // cout << "x before xor is " << x << endl;
        x ^= (pxor[l] ^ pxor[prev_l - 1]);
        // cout << "sandwiched xor is " << (pxor[l] ^ pxor[prev_l - 1]) << endl;
        // cout << "xored between " << l + 1 << "," << prev_l;
        // cout << " x after xor is " << x << endl;
      } else {
        x ^= (pxor[l]);
      }

      // cout << "next index: " << l << endl;
      // cout << endl;
    }

    cout << r - l << ' ';
  }

  cout << '\n';
 }
 return 0;
}