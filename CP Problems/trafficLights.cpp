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

class ComparisonClass
{
public:
 bool operator()(pair<int, int> p1, pair<int, int> p2)
 {
  // comparison code here
  return (p1.second - p1.first) - (p2.second - p2.first);
 }
};

int main()
{
 int n;
 int q;
 cin >> n >> q;
 set<int> set;
 multiset<int> multiset;

 set.insert(0);
 set.insert(n);

 multiset.insert(n - 0);

 for (int i = 0; i < q; i++) {
  int t;
  cin >> t;
  set.insert(t);
  auto cur = set.find(t);
  cur--;
  int low = *cur;
  cur++;
  cur++;
  int high = *cur;
  multiset.erase(multiset.find(high - low));
  
  multiset.insert(high - t);
  multiset.insert(t - low);
  auto last_element = multiset.rbegin();
  cout << *last_element << " ";
 }
 return 0;
}