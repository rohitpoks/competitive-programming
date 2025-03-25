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

int find_num_twos(int n) {
  int res = 0;
  while (n > 0) {
    if (n % 2 == 1) return res;
    res++;
    n /= 2;
  }

  return res;
}

void populate(vector<int>& num_twos) {
  num_twos[1] = 0;
  for (int i = 2; i <= 1e6; i++) {
    num_twos[i] = num_twos[i - 1] + find_num_twos(i);
  }
}

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 // given n, return the number of twos in the prime factorization of n!
 vector<int> num_twos(1e6 + 1, 0);
 populate(num_twos);
 while (t--) {
  int n, k;
  cin >> n >> k;
  n--;
  // print nth row of pascals triangle mod 2
  for (int i = 0; i <= n; i++) {
    // finding n choose i
    int total_num_twos = num_twos[n] - num_twos[i] - num_twos[n - i];
    if (total_num_twos > 0) {
      cout << 0 << " ";
    } else {
      cout << k  << " ";
    }
  }

  cout << '\n';
 }
 return 0;
}