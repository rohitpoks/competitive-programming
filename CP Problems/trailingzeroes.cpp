#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
 long n;
 cin >> n;
 long res = 0;

 long start = 5;
 while (start <= n) {
  
  res += (n / start);
  start *= 5;

 }

 cout << res;

 return 0;
}