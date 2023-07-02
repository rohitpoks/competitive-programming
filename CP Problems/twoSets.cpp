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
 long n;
 cin >> n;
 vector<long> a1;
 vector<long> a2;

 long t_sum = n * (n + 1) / 2;

 if (t_sum % 2 != 0)
 {
  cout << "NO";
  return 0;
 }

 cout << "YES" << endl;

 t_sum /= 2;
 for (long i = n; i >= 1; i--)
 {
  if (i <= t_sum)
  {
   a1.push_back(i);
   t_sum -= i;
  }
  else
  {
   a2.push_back(i);
  }
 }
 cout << a1.size() << endl;
 for (long i : a1)
 {
  cout << i << ' ';
 }
 cout << endl;
 cout << a2.size() << endl;
 for (long i : a2)
 {
  cout << i << ' ';
 }
 return 0;
}