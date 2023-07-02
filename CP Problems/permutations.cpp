#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{

 int n;
 cin >> n;
 if (n == 1)
 {
  cout << n;
  exit(0);
 }

 if (n == 4)
 {
  cout << "2 4 1 3";
  exit(0);
 }
 if (n <= 3)
 {
  cout << "NO SOLUTION";
  exit(0);
 }
 int even = 2;
 int odd = 1;
 for (int i = 0; i < n; i++)
 {
  if (odd <= n)
  {
   // print odd
   cout << odd << ' ';
   odd += 2;
  }
  else
  {
   cout << even << ' ';
   even += 2;
  }
 }
 return 0;
}