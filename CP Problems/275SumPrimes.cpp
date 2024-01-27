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


// bool checkPrime(int n) {
//  for (int i = 2; i <= n/2; i++) {
//   if (n%i == 0) return false;
  
//  }

//  return true;
// }
// int main() {

//  cout << checkPrime(10) << endl;
//  return 0;
// }

void f(int *x) {
 *x = 5;
}

int main() {
 int x = 4;
 f(&x);
 cout << x << endl;
}

