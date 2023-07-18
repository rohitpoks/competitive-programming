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
 int n;
 cin >> n;

 set<int> set;
 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;

  set.insert(a);
 }
 cout << set.size();
}