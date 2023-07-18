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
 int m;
 int n;
 cin >> m >> n;
 vector<int> customers;
 set<pair<int, int>> tickets;

 // say i want 4
 // you need to find <= 4
 // upper_bound = 4 + 1, that way you will get < 5
 for (int i = 0; i < m; i++)
 {
  int temp;
  cin >> temp;
  pair<int, int> pair_to_insert;
  pair_to_insert.first = temp;
  pair_to_insert.second = i;
  tickets.insert({temp, i});
 }

 for (int j = 0; j < n; j++)
 {
  int temp;
  cin >> temp;
  customers.push_back(temp);
 }
 vector<int> result;
 for (int j = 0; j < n; j++)
 {
  // if max price < lowest available ticket price print -1
  // get at or just bigger than max price
  // if at, print that
  // if just bigger, go back by 1 and print that
  // remove printed element
  if (customers[j] < (tickets.begin())->first || tickets.size() == 0)
  {
   result.push_back(-1);
   cout << result[j] << endl;
   continue;
  }

  auto next = tickets.upper_bound({customers[j], 0});

  if (next->first != customers[j])
   next--;
  result.push_back(next->first);
  tickets.erase(*next);

  cout << result[j] << endl;
 }

 return 0;
}