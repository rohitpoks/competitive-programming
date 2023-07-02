#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#define MAXSIZE 100020
using namespace std;

int children[MAXSIZE][2];
int height[MAXSIZE];
bool leftChild[MAXSIZE];
bool rightChild[MAXSIZE];
int parent[MAXSIZE];
int treeHeight;

int getHeight(int node)
{
 if (node == 0)
 {
  height[node] = 0;
  return 0;
 }
 int curHeight = 1 + max(getHeight(children[node][0]), getHeight(children[node][1]));
 height[node] = curHeight;
 return curHeight;
}

void printBST(int node)
{
 if (node == 0) return;
 printBST(children[node][0]);
 cout << node << '\n';
 printBST(children[node][1]);
}

int main()
{
 int actualSize = 0;
 cin >> actualSize;
 for (int i = 1; i <= actualSize; i++)
 {
  int l;
  int r;
  cin >> l;
  cin >> r;
  leftChild[l] = true;
  rightChild[r] = true;
  children[i][0] = l;
  children[i][1] = r;
  parent[l] = i;
  parent[r] = i;
 }
 treeHeight = getHeight(1);
 height[0] = 0;
 printBST(1);
 // for (int i = 1; i <= actualSize; i++)
 // {
 //  if (i == 1)
 //  {
 //   parent[i] = 0;
 //   cout << height[1] << '\n';
 //  }
 //  else
 //  {
 //   if (leftChild[i])
 //   {
 //    int p = parent[i];
 //    int x = i;
 //    int a = children[x][0];
 //    int b = children[x][1];
 //    int c = children[p][1];
 //    int offset = 0;
 //    if (parent[p] == 0 || p == 0) {
 //     offset = 0;
 //    } else {
 //     offset = treeHeight - height[parent[p]] + 1;
 //    }
 //    cout << offset + max(height[a] + 1, max(height[b], height[c]) + 2) << '\n';
 //   }
 //   else
 //   {
 //    int p = parent[i];
 //    int x = i;
 //    int b = children[x][0];
 //    int c = children[x][1];
 //    int a = children[p][0];
 //    int offset = 0;
 //    if (parent[p] == 0 || p == 0)
 //    {
 //     offset = 0;
 //    }
 //    else
 //    {
 //     offset = treeHeight - height[parent[p]] + 1;
 //    }
 //    cout << offset + max(height[c] + 1, max(height[a], height[b]) + 2) << '\n';
 //   }
  // }
 // }
}