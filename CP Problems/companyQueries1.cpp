#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


inline bool isPowerTwo(int i) {
    return i && !(i & (i - 1));
}


using ll = long long;
using namespace std;
const int MAX_NODES = 200001;
vector<int> graph[MAX_NODES];
int height[MAX_NODES] = {0};

int query(int node, int level) {
 while (level > 0) {
  // very inefficient
  //  int cur = (int) log2((double) level);
  int cur = __builtin_ctz(level);  // count trailing zeros
   if (cur >= graph[node].size()) {
    return -1;
   }
   node = graph[node][cur];
   if (node == 0) {
    return -1;
   }
   level -= (1 << cur);
  }
  if (level == 0) {
   return node;
  }

}
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, q;
 cin >> n;
 cin >> q;
 graph[1].push_back(0);

 for (int i = 2; i <= n; i++) {
  int b;
  cin >> b;
  height[i] = 1 + height[b];
  int first = 0;
  for (int b_boss : graph[b]) {
   int temp_res = query(b, first);
   if (temp_res != -1) graph[i].push_back(temp_res);
   first = (first + 1) * 2 - 1;
  }
  if (isPowerTwo(height[i]) && graph[i][graph[i].size() - 1] != 1) graph[i].push_back(1);
 }
 
 for (int i = 0; i < q; i++) {
  int node, level;
  cin >> node>> level;
  // inefficient:
  cout << query(node, level) << '\n';
 }
 return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// const int MAX_NODES = 200001;
// vector<int> graph[MAX_NODES];
// int height[MAX_NODES] = {0};

// inline bool isPowerTwo(int i) {
//     return i && !(i & (i - 1));
// }

// int query(int node, int level) {
//     while (level > 0) {
//         int cur = __builtin_ctz(level);  // count trailing zeros
//         if (cur >= graph[node].size()) {
//             return -1;
//         }
//         node = graph[node][cur];
//         if (node == 0) {
//             return -1;
//         }
//         level -= (1 << cur);
//     }
//     return node;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n, q;
//     cin >> n >> q;
//     graph[1].push_back(0);

//     for (int i = 2; i <= n; i++) {
//         int b;
//         cin >> b;
//         height[i] = 1 + height[b];
//         int first = 0;
//         for (int b_boss : graph[b]) {
//             int temp_res = query(b, first);
//             if (temp_res != -1) graph[i].push_back(temp_res);
//             first = (first + 1) * 2 - 1;
//         }
//         if (isPowerTwo(height[i]) && graph[i].back() != 1) graph[i].push_back(1);
//     }

//     for (int i = 0; i < q; i++) {
//         int node, level;
//         cin >> node >> level;
//         cout << query(node, level) << '\n';
//     }

//     return 0;
// }