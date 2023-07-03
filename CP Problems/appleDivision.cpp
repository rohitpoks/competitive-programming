#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

long findSum(long arr[], long sum1, long sum2, int index, int n)
{
 // either send arr[index] to left or right

 if (index == n) return abs(sum1-sum2);

 long a = findSum(arr, sum1 + arr[index], sum2, index + 1, n);

 long b = findSum(arr, sum1, sum2 + arr[index], index + 1, n);

 return min(a, b);
  
}



int main()
{
 int n;
 cin >> n;
 long arr[n];
 for (int i = 0; i < n; i++) {
  cin >> arr[i];
 }
 cout << abs(findSum(arr, 0, 0, 0, n));
 return 0;
} 

