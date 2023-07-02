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

 string input;
 cin >> input;
 int count = 1;
 int res = 1;
 for (int i = 1; i < input.length(); i++)
 {
  if (input[i - 1] == input[i])
   count++;
  else
   count = 1;
  res = max(res, count);
 }
 cout << res;
 return 0;
}