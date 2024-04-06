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

bool nonPalindrome(string s, int k) {
 int l = 0;
 int r = k-1;
 while (l < r) {
  if (s[l] != s[r]) return true;
  l++;
  r--;
 }
 l = 0;
 r = k-1;
 while (r < s.size()) {
  
  if (s[l] != s[r]) return true;
  l++;
  r++;
 }
 return false;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
   
  }
}