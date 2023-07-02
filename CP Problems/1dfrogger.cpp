#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

void frogger(int start, int board[201], int size, int goalVal)
{
 bool visited[201];
 for (int i = 1; i <= size; i++)
  visited[i] = false;
 int current = start;
 int hops = 0;
 while (current >= 1 && current <= size && board[current] != goalVal)
 {
  if (visited[current])
  {
   cout << "cycle\n";
   cout << hops << '\n';
   return;
  }
  visited[current] = true;
  hops++;
  current += board[current];
 }

 if (current < 1)
 {
  cout << "left\n";
 }
 else if (current > size)
 {
  cout << "right\n";
 }
 else
 {
  cout << "magic\n";
 }
 cout << hops << '\n';
}

int main()
{
 int n;
 int s;
 int m;
 int board[201];
 cin >> n;
 cin >> s;
 cin >> m;
 for (int i = 1; i <= n; i++)
 {
  cin >> board[i];
 }
 frogger(s, board, n, m);
}
