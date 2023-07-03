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

void printBoard(vector<vector<char> > board) {
 for (vector<char> b: board) {
  for (char c : b) {
   cout << c;
  }
  cout << endl;
 }
}

void updateBoard(int row, int col, vector<vector<char> >& board) {
 for (int i = 0; i < 8; i++) {
  board[i][col] = '*';
  board[row][i] = '*';
 }
 int x = row;
 int y = col;

 while (x < 8 && x >= 0 && y < 8 && y >= 0) {
  // top left
  board[x][y] = '*';
  x--;
  y--;
 }

 x = row;
 y = col;

 while (x < 8 && x >= 0 && y < 8 && y >= 0)
 {
  // top right
  board[x][y] = '*';
  x++;
  y--;
 }

 x = row;
 y = col;

 while (x < 8 && x >= 0 && y < 8 && y >= 0)
 {
  // bottom left
  board[x][y] = '*';
  x--;
  y++;
 }

 x = row;
 y = col;

 while (x < 8 && x >= 0 && y < 8 && y >= 0)
 {
  // bottom right
  board[x][y] = '*';
  x++;
  y++;
 }
}
int backtrack(int row, int col, int remaining, vector<vector<char> >& board) {
 if (remaining == 0) return 1;
 if (row == 7 && col == 8) return 0;
 if (col == 8) return backtrack(row + 1, 0, remaining, board);
 int ans = 0;
 if (board[row][col] == '.') {
  // can place here
  vector<vector<char> > temp = board;

  temp[row][col] = '*';
  updateBoard(row, col, temp);
  // printBoard(temp);
  // cout << "updating at row = " << row << " && col = " << col << endl;
  


  ans += backtrack(row, col + 1, remaining - 1, temp);
  // reverted board is "board"
 }

 // can't place here or already placed
 ans += backtrack(row, col + 1, remaining, board);

 return ans;

}



int main()
{
 vector<vector<char> > board;

 for (int i = 0; i < 8; i++) {
  string row;
  cin >> row;
  bool first = true;
  for (char c : row) {
   if (first) {
    vector<char> temp;
    temp.push_back(c);
    board.push_back(temp);
    first = false;
    continue;
   } 
   board[i].push_back(c);
  }
 }
 cout << backtrack(0, 0, 8, board);
}

