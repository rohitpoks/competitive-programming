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

bool check_associativity(vector<vector<int> >& cayley_table, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) { 
        // case 1: perform (i * j) * k
        int case1 = cayley_table[cayley_table[i][j]][k];
         // case 2: perform i * (j * k)
        int case2 = cayley_table[i][cayley_table[j][k]];
        cout << "checking for (" << i << "," << j << "," << k << ")" << ", case 1: " << case1 << ", and case 2 : " << case2 << endl;
        if (case1 != case2) return false;
      }
    }
  }

  return true;
}


void print_table(vector<vector<int> >& cayley_table) {
  int n = cayley_table.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << cayley_table[i][j] << ' ';
    }
    cout << endl;
  }
}


bool can_fit(int i, vector<vector<int> >& cayley_table, int row, int col, int n) {
  for (int j = 0; j < n; j++) {
    if (cayley_table[row][j] == i || cayley_table[j][col] == i) return false;
  }

  return true;
}


int find_unique(int n, vector<vector<int> >& cayley_table, int next_row, int next_col) {
  if (next_row == n && next_col == 0) {
    // print_table(cayley_table);
    // return check_associativity(cayley_table, n);
    return 1;
  }

  if (next_col == 0) return find_unique(n, cayley_table, next_row, next_col + 1);
  if (next_col == n) return find_unique(n, cayley_table, next_row + 1, 0);


  int total = 0;
  for (int i = 0; i < n; i++) {
    if (can_fit(i, cayley_table, next_row, next_col, n)) {
      cayley_table[next_row][next_col] = i;
      total += find_unique(n, cayley_table, next_row, next_col + 1);
      cayley_table[next_row][next_col] = -1;
    }
  }

  return total;
}


int num_unique_groups(int n) {
  vector<vector<int > > cayley_table(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    cayley_table[i][0] = i;
    cayley_table[0][i] = i;
  }

  return find_unique(n, cayley_table, 1, 0);
}
int main() {
  cout << num_unique_groups(4) << endl;
  return 0;
}