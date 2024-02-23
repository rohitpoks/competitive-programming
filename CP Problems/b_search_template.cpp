#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <climits>

using ll = long long;
using namespace std;
// call b_search with {-1,n}
// returns {arr[l] < x <= arr[r] assuming indices are valid}
void b_search(vector<ll>& prefix, int m, int& l, int& r) {
 if (r == l + 1) return;
 int mid = l + (r-l)/2;
 // next line is pivotal, decides arr[l] < x <= arr[r]
 // (prefix[mid] <= m) l = mid would determine <= x <
 if (prefix[mid] >= m) r = mid; 
 else l = mid;
 b_search(prefix, m, l, r);
}