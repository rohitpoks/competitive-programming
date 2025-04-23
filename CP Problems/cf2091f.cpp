#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <climits>
#include <cassert>

using ll = long long;
using namespace std;

const ll MOD = 998244353;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int iterations = 0;
  int n, m, d;
  cin  >> n >> m >> d;
  int dp[n + 10][m + 10][2];
  ll ps[n + 10][m + 10][2];
  memset(dp, 0, sizeof(dp));
  memset(ps, 0, sizeof(ps));
  vector<vector<char> > brd(n, vector<char>(m, '.'));

  // O(mn)
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      brd[i][j] = s[j];
    }
  }

  ll first_ps[m + 10];
  memset(first_ps, 0, sizeof(ps));
  for (int i = 0; i < m; i++) {
    // this row has already been taken. one path from this 'X'
    dp[0][i][1] = (brd[0][i] == 'X');
    first_ps[i + 1] = first_ps[i];
    first_ps[i + 1] += (brd[0][i] == 'X');
  }

  // then, set for ! r_t
  for (int i = 0; i < m; i++) {
    dp[0][i][0] = first_ps[min(m - 1, i + d) + 1] - first_ps[max(0, i - d)];

    if (brd[0][i] =='#') dp[0][i][0] = 0;
  }

  for (int i  = 0; i < 1; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k <= 1; k++) {
        ps[i][j + 1][k] = ps[i][j][k];
        ps[i][j+1][k] += dp[i][j][k];
        ps[i][j+1][k] = (ps[i][j+1][k] + MOD) % MOD;
      }
    }
  }

  int r  = sqrt(d * d - 1);
  ll res = 0;
  for (int row = 1; row < n; row++) {
    for (int r_t = 1; r_t >= 0; r_t--) {
      for (int col = 0; col < m; col++) {
        iterations++;
        if (!r_t) {
          // add same row first, only do this if same row not taken
          int L = max(col -d, 0); int R = min(col + d, m - 1);
          dp[row][col][r_t] += (ps[row][R + 1][1] - ps[row][L][1]);
          dp[row][col][r_t] -= dp[row][col][1];
          dp[row][col][r_t] = (dp[row][col][r_t] + MOD) % MOD;
        }
        // add prev row
        int L = max(col - (int) r, 0);
        int R = min(col + (int) r, m - 1);

        // update psum
        dp[row][col][r_t] += (ps[row - 1][R + 1][0] - ps[row - 1][L][0]);
        dp[row][col][r_t] = (dp[row][col][r_t] + MOD) % MOD;

        if (brd[row][col] == '#') dp[row][col][r_t] = 0;
        // update psum here
        ps[row][col + 1][r_t] = ps[row][col][r_t];
        ps[row][col + 1][r_t] += dp[row][col][r_t];
        ps[row][col + 1][r_t] = (ps[row][col + 1][r_t] + MOD) % MOD;

        if ((row == n - 1) && (r_t == 0)) {
          res += dp[n-1][col][0];
          res %= MOD;
        }
      }
    }
  }
  cout << res << '\n';
 }
 return 0;
}