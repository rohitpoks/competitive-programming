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
using namespace std;

int main()
{
 int n;
 cin >> n;

 vector<int> nums;
 unordered_map<int, int> map;

 for (int i = 0; i < n; i++) {
  int temp;
  cin >> temp;
  nums.push_back(temp);

  map.insert({temp, i});
 }
 int res = 0;
 for (int i = 2; i <= n; i++) {
  if (map[i - 1] > map[i]) {
   res++;
  }
 }
 cout << res + 1;
 
}