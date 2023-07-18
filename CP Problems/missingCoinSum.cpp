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
 int n; 
 cin >> n;
 vector<int> coins;
 for (int i = 0; i < n; i++) {
  int temp;
  cin >> temp;
  coins.push_back(temp);
 }
 sort(coins.begin(), coins.end());
 long looking_for = 1;
 for (int i = 0; i < n; i++) {
  if (coins[i] <= looking_for) {
   looking_for += coins[i];
  } else {
   break;
  }
 }
 cout << looking_for;
 return 0;
}