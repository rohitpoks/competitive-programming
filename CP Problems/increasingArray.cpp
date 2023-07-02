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
 long arr[n];

 for (long i = 0; i < n; i++)
 {
  cin >> arr[i];
 }
 long res = 0;
 for (long i = 1; i < n; i++)
 {
  if (arr[i - 1] > arr[i])
  {
   res += arr[i - 1] - arr[i];
   arr[i] = arr[i - 1];
  }
 }
 cout << res;
 return 0;
}