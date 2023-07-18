#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

vector<string> create(long n)
{
 vector<string> res;
 int edge1 = n / 2;
 int edge2 = n / 2;
 int mid = n;
 int midCount = 0;
 for (int i = 0; i < n; i++)
  res.push_back("");

 for (int k = 0; k < (int) log2(n); k++)
 {
  int resIndex = 0;
  for (int i = 0; i < edge1; i++)
  {
   res[resIndex].append("0");
   resIndex++;
  }
  edge1 /= 2;
  string c = "1";
  for (int outer = 0; outer < midCount; outer++)
  {
   for (int i = 0; i < mid; i++)
   {
    res[resIndex].append(c);
    resIndex++;
   }
   if (c == "0")
    c = "1";
   else
    c = "0";
  }

  mid /= 2;
  if (edge1 != 0) midCount = ((n / edge1) - 2) / 2;

  for (int i = 0; i < edge2; i++)
  {
   if (c == "0")
    res[resIndex].append("0");
   else
    res[resIndex].append("1");
   resIndex++;
  }

  edge2 /= 2;
 }
 return res;
}

vector<string> createRecursive(int n) {
 if (n == 1) return { "0", "1"};
 vector<string> oneLess = createRecursive(n - 1);
 vector<string> res;
 for (int i = 0; i < oneLess.size(); i++) {
  res.push_back("0" + oneLess[i]);
 }

 for (int i = oneLess.size() - 1; i>=0; i--) {
  res.push_back("1" + oneLess[i]);
 }

 return res;
}

int main()
{
 int n;
 cin >> n;
 vector<string> res = createRecursive(n);

 for (string s : res)
 {
  cout << s << endl;
 }
 return 0;
}