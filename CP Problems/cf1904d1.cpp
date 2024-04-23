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

int main() {
 ios_base::sync_with_stdio(false);
 int t;
 cin >> t;
 while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        // find on right side
        int cur = a[i];
        for (int j = i; j < n; j++) {
            if (b[j] < b[i]) break;
            cur = max(cur, a[j]);
            if (cur > b[i]) break;
            if (cur == b[i]) {
                res[i] = b[i];
                break;
            }
        }
        if (res[i] == b[i]) continue;
        cur = a[i];
        for (int j = i; j >= 0; j--) {
            if (b[j] < b[i]) break;
            cur = max(cur, a[j]);
            if (cur > b[i]) break;
            if (cur == b[i]) {
                res[i] = b[i];
                break;
            }
        }
    }
    bool yes = true;
    for (int i = 0; i < n; i++) {
        if (res[i] != b[i]) yes = false;
    }
    yes ? cout << "yes\n" : cout << "no\n";
 }
 return 0;
}