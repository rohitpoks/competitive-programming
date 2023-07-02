#include <iostream>
#include <stdio.h>

using namespace std;

int opt[1000][1000];
int T[6][6]; 

int main() {
 // row 1
 T[0][0] = 5;
 T[0][1] = 2;
 T[0][2] = 1;
 T[0][3] = 3;
 T[0][4] = 4;
// row 2
 T[1][0] = 2;
 T[1][1] = 3;
 T[1][2] = 4;
 T[1][3] = 6;
 T[1][4] = 1;
 // row 3
 T[2][0] = 2;
 T[2][1] = 4;
 T[2][2] = 4;
 T[2][3] = 5;
 T[2][4] = 3;
 // row 4
 T[3][0] = 4;
 T[3][1] = 5;
 T[3][2] = 9;
 T[3][3] = 8;
 T[3][4] = 7;
 // row 5
 T[4][0] = 12;
 T[4][1] = 14;
 T[4][2] = 7;
 T[4][3] = 2;
 T[4][4] = 1;

 // if you can loot as many boxes as you want
 for (int i = 0; i < 5; i++) {
  for (int j = 0; j < 5; j++) {
   if (i == 0) opt[i][j] = T[i][j];
   else {
    if (j == 0) opt[i][j] = max(opt[i - 1][j], opt[i-1][j+1]);
    else if (j == 4) opt[i][j] = max(opt[i - 1][j], opt[i-1][j-1]);
    else opt[i][j] = max(max(opt[i-1][j-1],opt[i-1][j]), opt[i-1][j+1]);
    opt[i][j] += T[i][j];
   }
  }
 }
 int highest = 0;
 for (int j = 0; j < 5; j++) {
  highest = max(opt[4][j], highest);
 }
 cout << highest;


 // say you are only allowed to look k boxes --> let's say 3 in this case

 dp[1000][1000][1000];

 for (int i = 0; i < 5; i++) {
  for (int j = 0; j < 5; j++) {
   dp[i][j][0] = 0;
  }
 }

 for (int j = 0; j < 5; j++) {
  // k indicates: you've made your decision, then how many boxes u have left
  for (int k = 0; k <= 3; k++) {
   dp[i][j][k] =  
  }
 }
}