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

long digitAt(long number, long digitNumber) {
 while (digitNumber > 0) {
  number = number / 10;
  digitNumber--;
 }
 return number % 10;
}

long nDigits(long n) {
 if (n >= 1 && n <= 9) return 1;
 return 1 + nDigits(n/10);
}

int main()
{
 long q;
 long k;
 cin >> q;
 for (int i = 0; i < q; i++)
 {
  cin >> k;
  long numberOfDigits = 1;
  long start = 1;
  long end = 9;
  while (k > 0) {
   k -= (end - start + 1) * numberOfDigits;
   numberOfDigits += 1;
   start *= 10;
   end = end * 10 + 9;
  }
  numberOfDigits -= 1;
  start /= 10;
  end = end - 9;
  end = end / 10;
  k += (end - start + 1) * numberOfDigits;

  long number = start + (k - 1) / numberOfDigits;
  long digitNumber = (k % numberOfDigits);
  if (digitNumber == 0) digitNumber = numberOfDigits;
  cout << digitAt(number, numberOfDigits - digitNumber) << endl;
  
 }
 return 0;
}