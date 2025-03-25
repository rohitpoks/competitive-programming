#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
  int x, n, m;
  cin >> x >> n >> m;
  for (int _ = 0; _ < 2; _++) {
    int _x = x;
    int _m = m;
    int _n = n;
    // _m: number of c's left
    // _n: number of f's left
    if (_ == 0) {
      // compute min value
      while (_x > 1 && ((_n + _m) > 0)) {
        // greedily apply ceil first
        if (_m) {
          _m--;
          if (_x % 2) {
            _x/= 2;
            _x++;
          } else {
            _x/= 2;
          }
        } else {
          _n--;
          _x/= 2;
        }
      }

      if (_n > 0) _x = 0;
      cout << _x << ' ';
    } else {
      // compute max value
      while (_x > 1 && ((_n + _m) > 0)) {
        if (_n) {
          _n--;
          _x /= 2;
        } else {
          _m--;
          if (_x % 2) {
            _x/= 2;
            _x++;
          } else {
            _x/= 2;
          }
        }
      }

      if (_n > 0) _x = 0;
      cout << _x << '\n';
    }
  }
 }

 return 0;
}