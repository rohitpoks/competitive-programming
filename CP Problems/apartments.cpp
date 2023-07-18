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
 vector<int> people;
 vector<int> apts;

 int m;
 int n;
 int k;
 cin >> n;
 cin >> m;
 cin >> k;

 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  people.push_back(a);
 }

 for (int i = 0; i < m; i++) {
  int a;
  cin >> a;
  apts.push_back(a);
 }

 sort(apts.begin(), apts.end());
 sort(people.begin(), people.end());
 int a = apts.size() - 1;
 int res = 0;
 for (int p = people.size() - 1; p >= 0; p--) {

  while (apts[a] > people[p] + k)
  {
   a--;

   if (a < 0)
    break;

  }

  if (apts[a] >= people[p] - k && apts[a] <= people[p] + k) {
   res++;
   a--;
  }
  
  if (a < 0) break;
 }
 cout << res;
}
