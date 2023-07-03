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

vector<string> permute(string s)
{

 vector<string> result;
 if (s.length() == 0 || s.length() == 1)
 {
  result.push_back(s);
  return result;
 }

 for (int i = 0; i < s.size(); i++)
 {
  vector<string> subres;

  while (i > 0 && i < s.length() && s[i] == s[i - 1])
   i++;
  if (i == s.length())
   break;
  subres = permute(s.substr(0, i) + s.substr(i + 1));

  for (string subs : subres)
  {
   result.push_back(s.substr(i, 1) + subs);
  }
 }
 return result;
}

int fact(int n)
{
 return (n == 0) ? 1 : n * fact(n - 1);
}

int main()
{
 string input;

 cin >> input;
 sort(input.begin(), input.end());
 vector<string> res = permute(input);
 cout << res.size() << endl;
 for (auto i = res.begin(); i != res.end(); i++)
 {
  cout << *i << endl;
 }
 return 0;
}
