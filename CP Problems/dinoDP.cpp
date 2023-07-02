#include <iostream>
#include <stdio.h>
using namespace std;

int optT[10];
int optV[10];
int t[10];
int v[10];

int main() {
 int p = 2;
 for (int i = 0; i <= 9; i++) {
  t[i] = i * 2 - 1;
  v[i] = i * 3 - 5;
  optV[i] = 0;
  optT[i] = 0;
 }

 optV[0] = v[0];
 optT[0] = t[0];

 for (int i = 1; i <= 9; i++) {
  optV[i] = max(optV[i - 1] + v[i], optT[i - 1] + v[i] - p);
  optT[i] = max(optT[i-1] + t[i], optV[i-1] + t[i] - p);
 }
 for (int i = 0; i <= 9; i++) {
  cout << "for i = " << i << " optT is " << optT[i] << " optV is " << optV[i] << "\n";
 }
}