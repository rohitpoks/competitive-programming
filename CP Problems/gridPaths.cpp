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
bool board[7][7];
string path;
int n_paths(int index, int x, int y)
{

 // can either go right, up, left, down
 if (x == 0 && y == 6 && index == 48)
  return 1;

 if (x == 0 && y == 6)
  return 0;
 if (x < 0 || x >= 7 || y < 0 || y >= 7)
  return 0;
 if (board[x][y])
  return 0;

 // moved all the way to the right but 0, 6 not covered

 // if ((right - left == 6) && (x != 6 && y != 0) && !board[0][6])
 //  return 0;
 // // at bottom but bottom right not covered
 // if ((down - up == 6) && (x != 6 && y != 6) && !board[6][6])
 //  return 0;

 if (x - 1 >= 0 && y - 1 >= 0)
 {
  if (board[x - 1][y - 1] && !board[x][y - 1] && !board[x - 1][y])
   return 0;
 }

 if (x + 1 <= 6 && y + 1 <= 6)
 {
  if (board[x + 1][y + 1] && !board[x + 1][y] && !board[x][y + 1])
   return 0;
 }

 if (x + 1 <= 6 && y - 1 >= 0)
 {
  if (board[x + 1][y - 1] && !board[x][y - 1] && !board[x + 1][y])
   return 0;
 }

 if (x - 1 >= 0 && y + 1 <= 6)
 {
  if (board[x - 1][y + 1] && !board[x - 1][y] && !board[x][y + 1])
   return 0;
 }

 int ans = 0;
 board[x][y] = true;
 if (path[index] == '?')
 {
  // any direction
  ans = n_paths(index + 1, x, y + 1) + n_paths(index + 1, x + 1, y) + n_paths(index + 1, x - 1, y) + n_paths(index + 1, x, y - 1);
  board[x][y] = false;
  return ans;
 }
 if (path[index] == 'U')
  ans = n_paths(index + 1, x, y - 1);
 else if (path[index] == 'R')
  ans = n_paths(index + 1, x + 1, y);
 else if (path[index] == 'L')
  ans = n_paths(index + 1, x - 1, y);
 else
  ans = n_paths(index + 1, x, y + 1);
 board[x][y] = false;
 return ans;
}
int main()
{
 path = "??????R??????U??????????????????????????LD????D?";
 // path = "DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD";
 // cin >> path;

 for (int i = 0; i < 7; i++)
 {
  for (int j = 0; j < 7; j++)
  {
   board[i][j] = false;
  }
 }
 cout << n_paths(0, 0, 0);
}