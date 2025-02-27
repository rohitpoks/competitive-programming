#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <climits>

using ll = long long;
using namespace std;

void solve(const string& s, int n) {
  vector<int> oddSoFar(26, 0);
  vector<int> evenSoFar(26, 0);
  vector<int> oddTotal(26, 0);
  vector<int> evenTotal(26, 0);

  for (int i = s.size() - 1; i >= 0; i--) {
    int c = s[i] - 'a';
    if (i % 2 == 0) {
      evenTotal[c]++;
    } else {
      oddTotal[c]++;
    }
  }

  int result = n;
  for (int i = s.size() - 1; i >= 0; i--) {
    int c = s[i] - 'a';
    vector<int> oddTotalCopy = oddTotal;
    vector<int> evenTotalCopy = evenTotal;
    
    // remove current character
    int cEMax = 0;
    int cOMax = 0;
    // cout << "removing " << (char) (c + 'a') << endl;
    if (i % 2 == 1) {
      oddTotalCopy[c] -= 1;
    } else {
      evenTotalCopy[c] -= 1;
    }

    for (int k = 0; k <= 25; k++) {
      oddTotalCopy[k] -= oddSoFar[k];
      evenTotalCopy[k] += oddSoFar[k];
      evenTotalCopy[k] -= evenSoFar[k];
      oddTotalCopy[k] += evenSoFar[k];
      cEMax = max(cEMax, evenTotalCopy[k]);
      cOMax = max(cOMax, oddTotalCopy[k]);
    }

    // cout << "max even and odd is " << cEMax << "," << cOMax << endl;
    result = min(result, n - 1 - cEMax - cOMax);

    if (i % 2 == 0) {
      evenSoFar[c]++;
    } else {
      oddSoFar[c]++;
    }
  }

  if (n % 2 == 1) {
    cout <<  result + 1 << '\n';
    return;
  }

  int cEMax = 0;
  int cOMax = 0;
  for (int i = 0; i < 26; i++) {
    cEMax = max(cEMax, evenTotal[i]);
    cOMax = max(cOMax, oddTotal[i]);
  }

  int evenResult = n - cEMax - cOMax;

  cout << evenResult << '\n';
}

int main() {
 ios_base::sync_with_stdio(false);

 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  solve(s, n);
 }


 return 0;
}