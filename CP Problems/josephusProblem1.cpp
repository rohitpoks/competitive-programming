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
 int n;
 cin >> n;

 set<int> set;
 for (int i = 1; i <= n; i++)
 {
  set.insert(i);
 }
 int count = 0;
 auto iter = set.begin();
 while (count != n)
 {
  iter++;
  if (iter == set.end())
   iter = set.begin();
  int val = *iter;
  cout << val << " ";
  iter++;
  if (iter == set.end())
   iter = set.begin();
  set.erase(val);
  count++;
 }
}