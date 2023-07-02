#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;


void simulate(int n, int from, int to, int mid) {
 if (n == 1) {
  cout << from << ' ' << to << endl;
  return;
 }

 // to solve the larger problem

 simulate(n - 1, from, mid, to);
 simulate(1, from, to, mid);
 simulate(n-1, mid, to, from);
 

}

int main() {
 int n;
 cin >> n;
 cout << (int) (pow(2, n) - 1) << endl;
 simulate(n, 1, 3, 2);
}
