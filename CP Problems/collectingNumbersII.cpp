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
 int m;

 cin >> n >> m;
 vector<int> nums;
 unordered_map<int, int> map;
 map[0] = -1;
 map[n + 1] = n;
 for (int i = 0; i < n; i++) {
  int temp;
  cin >> temp;
  nums.push_back(temp);
  map[temp] = i;
 }

 int res = 1;

 for (int i = 2; i <= n; i++) {
  if (map[i - 1] > map[i]) res++;
 }

 for (int i = 0; i < m; i++) {
  
  int a;
  int b;
  cin >> a >> b;
  // 0 indexed
  a--;
  b--;
  
  int first = nums[a];
  int second = nums[b];
  int first_incoming_position = map[first - 1];
  int first_outgoing_position = map[first + 1];
  int second_incoming_position = map[second - 1];
  int second_outgoing_position = map[second + 1];
  // swap them
  int temp = nums[a];
  nums[a] = nums[b];
  nums[b] = temp;
  // calculate old position
  if ( (first_incoming_position > a && first_incoming_position > b) || (first_incoming_position < a && first_incoming_position < b)) {
  } else {
   // new position on the right side
   if (b > a) res--;
   else res++;
  }

  if ((first_outgoing_position > a && first_outgoing_position > b) || (first_outgoing_position < a && first_outgoing_position < b)) {
  } else {
   // change sth here
   if (b > a)
    res--;
    else res++;
  }

  if ((second_incoming_position > a && second_incoming_position > b) || (second_incoming_position < a && second_incoming_position < b))
  {
  }
  else
  {
   // change sth here
    if (a > b)
    res--;
    else
    res++;
  }

  if ((second_outgoing_position > a && second_outgoing_position > b) || (second_outgoing_position < a && second_outgoing_position < b))
  {
  }
  else
  {
   // change sth here
    if (a > b)
    res--;
    else
    res++;
  }
  cout << res << endl;
 }

}