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
 int z;
 cin >> z;
 for (int q = 0; q < z; q++) {
  int rounds;
  cin >> rounds;
  char trump;
  cin >> trump;
  map<char, vector<int> > cards;
  map<string, int> order;
  for (int i = 0; i < 2 * rounds; i++) {
   string card;
   cin >> card;
   cards[card[1]].push_back(card[0] - '0');
   order[card] = i;
  }
  // check if trump card is greater than or equal to %1 of other cards
  int num_of_trump = 0;
  int rem = 0;
  for (pair<char, vector<int> > p : cards) {
   if (p.first == trump) num_of_trump = p.second.size();
   else rem += (p.second.size())%2;
  }
  if (num_of_trump < rem) {
   cout << "IMPOSSIBLE";
   continue;
  }
  // match every 2 characters
  vector<string> remaining;
  for (pair<char, vector<int> > p : cards) {
   if (p.first == trump) continue;
   if (p.second.size() == 1) {
    remaining.push_back(to_string(p.second.back()) + p.first);
    p.second.pop_back();
    continue;
   }
   int a = p.second.back();
   p.second.pop_back();
   int b = p.second.back();
   p.second.pop_back();
   cout << a << p.first << ' ' << b << p.first << '\n';
  }
  for (string s : remaining) {
   cout << s << ' ' << cards[trump].back() << trump << '\n';
   cards[trump].pop_back();
  }
  int s = cards[trump].size();
  for (int i = 0; i < s/2; i++) {
   int a = cards[trump].back();
   cards[trump].pop_back();
   int b = cards[trump].back();
   cards[trump].pop_back();
   cout << a << trump << ' ' << b << trump << '\n';
  }
 }
 return 0;
}