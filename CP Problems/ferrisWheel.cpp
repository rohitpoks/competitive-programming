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
using namespace std;

int main()
{
 vector<int> weights;
 int n;
 int maxWeight;

 cin >> n;
 cin >> maxWeight;

 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  weights.push_back(a);
 }

 sort(weights.begin(), weights.end());
 int ans = 0;
 int right = weights.size() - 1;
 int left = 0;
 while (left <= right) {
  if (weights[left] + weights[right] <= maxWeight) {
   left++;
   right--;
  } else {
   right--;
  }
  ans += 1;
 }
 cout << ans;
}