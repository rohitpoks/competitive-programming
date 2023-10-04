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

int main()
{
 vector<int> nums;

 set<int> set;

 int n;

 cin >> n;

 for (int i = 0; i < n; i++)
 {

  int temp;
  cin >> temp;

  nums.push_back(temp);

 }
 int left = 0;
 set.insert(nums[0]);
 int res = 1;
 for (int right = 1; right < n; right++) {
  while (right > left && set.count(nums[right]) > 0) {
   // remove any duplicates
   set.erase(nums[left]);
   left++;
  }

  set.insert(nums[right]);
  res = max(res, right - left + 1);
 }
 cout << res;
}