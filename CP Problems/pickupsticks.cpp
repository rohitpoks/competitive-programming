#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
int m;
int nSticks;
void topologicalSort(bool added[], int incoming[], vector<int> neighbors[])
{
 vector<int> result;
 queue<int> q;
 for (int i = 1; i <= nSticks; i++)
 {
  if (incoming[i] == 0)
  {
   q.push(i);
  }
 }

 while (!q.empty())
 {
  int current = q.back();
  q.pop();
  result.push_back(current);

  for (int i = 0; i < neighbors[current].size(); i++)
  {
   incoming[neighbors[current].at(i)]--;
   if (incoming[neighbors[current].at(i)] == 0 && !added[neighbors[current].at(i)])
   {
    q.push(neighbors[current].at(i));
    added[neighbors[current].at(i)] = true;
   }
  }
 }

 if (result.size() == nSticks)
 {
  for (int i = 0; i < nSticks; i++)
  {
   cout << result.at(i) << '\n';
  }
 }
 else
 {
  cout << "IMPOSSIBLE\n";
 }
}

int main()
{
 cin >> nSticks;
 cin >> m;
 bool added[nSticks + 1];
 int incoming[nSticks + 1];
 vector<int> neighbors[nSticks + 1];
 for (int i = 0; i <= nSticks; i++)
 {
  incoming[i] = 0;
  added[i] = false;
 }
 for (int i = 0; i < m; i++)
 {
  int a;
  int b;
  cin >> a;
  cin >> b;
  neighbors[a].push_back(b);
  incoming[b]++;
 }
 topologicalSort(added, incoming, neighbors);
}
