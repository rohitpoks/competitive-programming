#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>

using ll = long long;
using namespace std;

int main() {
 unsigned long long n;

 cin >> n;

 vector<unsigned long long> arr(n);

 for (unsigned long long i = 0; i < n; i++) {
  cin >> arr[i];
 }

 

 vector<vector<unsigned long long> > bits(n, vector<unsigned long long>(64, 0));
 vector<unsigned long long> ones = vector<unsigned long long>(64,0);
 vector<unsigned long long> zeros = vector<unsigned long long>(64,0);
 // how many zeros/ones for this column?
 for (unsigned long long i = 0; i < n; i++) {
  unsigned long long cur = arr[i];
  // cout << "here" << endl;
  for (unsigned long long j = 0; j <= 60; j++) {
   bits[i][j] = cur %(unsigned long long)2;
   if (cur % (unsigned long long)2 == 0) {
    zeros[j]++;
   } else {
    ones[j]++;
   }
   cur /= 2ULL;
  }
 }
 unsigned long long ans = 0ULL;

 for (unsigned long long i = 0; i <= 60; i++) {
  unsigned long long cur = 0;
  
  unsigned long long one = ones[i];
  unsigned long long zero = zeros[i];
  cur = one * zero;
  ans += (((1ULL << i)%(1000000007ULL))*cur)%1000000007ULL;
  ans %= 1000000007ULL;
 }
 cout << ans %1000000007ULL;

}