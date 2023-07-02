#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;


long exp(long n) {
 if (n == 1) return 2;
 long a, b; 
 a = n / 2;
 b = (n - n / 2);
 return (exp(a) * exp(b)) % 1000000007;
}
int main()
{
 long n;
 cin >> n;
 cout << exp(n);
 return 0;
}
