#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;


// implement graph as an adjacency matrix

int original[100][100];
int flow[100][100];
int residual[100][100];
bool done[100][100];

void constructResidual()
{
 for (int i = 0; i <= 99; i++)
 {
  for (int j = 0; j <= 99; j++)
  {
   if (flow[i][j] > 0)
   {
    residual[j][i] = flow[i][j];
    residual[i][j] = original[i][j] - flow[i][j];
   }
  }
 }
}
// dfs to find max, look at the residual graph
int findMin(int current, int sink)
{
 if (current == sink)
  return INT_MAX;
 // for every edge that it connects to
 int local_min = INT_MAX;
 for (int i = 0; i <= 99; i++)
 {
  if (residual[current][i] > 0 && !done[current][i])
  {
   done[current][i] = true;
   local_min = min(residual[current][i], findMin(i, sink));
  }
 }
 return local_min;
}



int main() {

 for (int i = 0; i <= 99; i++) {
  for (int j = 0; j <= 99; j++) {
   original[i][j] = 0;
   flow[i][j] = 0;
   residual[i][j] = 0;
   done[i][j] = false;
  }
 }
 original[1][2] = 1;
 original[2][4] = 1;
 original[4][6] = 1;
 original[1][3] = 1;
 original[3][5] = 1;
 original[5][6] = 1;

 flow[1][2] = 1;
 flow[2][4] = 1;
 flow[4][6] = 1;
 flow[1][3] = 1;
 flow[3][5] = 1;
 flow[5][6] = 1;

 //

 constructResidual();
 cout << findMin(1, 6);

}

