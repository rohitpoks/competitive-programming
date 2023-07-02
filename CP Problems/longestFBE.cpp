#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<char, char> map;
string input;
int dp[1000][1000];



int opt(int i, int j) {
 if (i == j) return 2;
 if (j < i) return 0;
 if (dp[i][j] != -1) return dp[i][j];
 if (map.count(input[i]) > 0) {
  int addCustom = 2 + opt(i + 1, j);
  int curAns = INT_MAX;
  for (int k = i + 1; k <= j; k++) {
   if (map[input[i]] == input[k]) curAns = min(curAns, 2 + opt(i + 1, k - 1) + opt(k + 1, j));
  }
  return dp[i][j] = min(addCustom, curAns);
 }
 // closing bracket
 return dp[i][j] = 2 + opt(i + 1, j);

}



 int findFBE(string input) {

  for (int i = 0; i < input.length(); i++) {
   for (int j = 0; j < input.length(); j++) {
    if (i == j) dp[i][j] = 2;
    if (j < i) dp[i][j] = 0;
   }
  }

  for (int j = 0; j < input.length(); j++) {
   for (int i = j; i >= 0; i--) {
      int custom = 2 + dp[i + 1][j];
      int curAns = 10000;
    for (int k = i + 1; k <= j; k++)
    {
     if (map[input[i]] == input[k])
      curAns = min(curAns, 2 + dp[i + 1][k - 1] + dp[k + 1][j]);
      }
      dp[i][j] = min(curAns, custom);
   }
  }

  return dp[0][input.length() - 1];
 }

 int main()
 {
  input = "]){{}}}}]]]]][][[{";

  map['('] = ')';
  map['['] = ']';
  map['{'] = '}';

  cout << findFBE(input);
 }

