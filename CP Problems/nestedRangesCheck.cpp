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
#include <stack>

using ll = long long;
using namespace std;

class CustomComparator {
 // x1, x2: x1 comes first if x1 starts before x2, or they start at the same time and x1 ends first
 bool operator() (pair<int, int> p1, pair<int, int> p2) {
  if (p1.first < p2.first) return true;
  if (p1.first == p2.first) {
   // start at same time
   return (p1.first == -1);
  }
  return false;
 }
};


class TimeStamp {

  public:
  int val;
  int outer;
  int inner;
  bool s;

  
  TimeStamp(int val, bool s) {
   this->val = val;
   this->s = s;
  }
  struct compare {
   bool operator()(TimeStamp* o1, TimeStamp* o2) {
   if (o1->val < o2->val) return false; 
   if (o1->val == o2->val && o1->s == false) return false; 
   return true;
  }
  };
  
 };


int main() {

 // -1 represents end
 // 1 represents start

 int n;
 cin >> n;


 


 stack<TimeStamp*> stack;

 priority_queue<TimeStamp*, vector<TimeStamp*>, TimeStamp::compare> pq;
 vector<TimeStamp*> order;
 for (int i = 0; i < n; i++) {
  int s, e;
  cin >> s >> e;
  TimeStamp* t1 = new TimeStamp(s, true);
  TimeStamp* t2 = new TimeStamp(e, false);

  pq.push(t1);
  pq.push(t2);

  order.push_back(t1);
 }

 while (!pq.empty()) {

  TimeStamp* next = pq.top();
  pq.pop();

  cout << "currently looking at " << next->val << " and it is " << next->s << endl;

  if (next->s) {
   stack.push(next);
   continue;
  }

  // next is a closing timestamp
  
  TimeStamp* nextStart = stack.top();
  stack.pop();

  nextStart->outer = stack.size();

  if (!stack.empty()) {
   stack.top()->inner = 1 + nextStart->inner;
  }
 }

 for (TimeStamp* o: order) {
  cout << o-> inner << ' ';
 }
 cout << endl;

 for (TimeStamp* o : order) {
  cout << o-> outer << ' ';
 }

 cout << endl;
 return 0;
}