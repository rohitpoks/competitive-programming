#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
 vector<int> values = {2, 4, 6, 8, 10};
 unordered_set<string> set = {"rohit", "harsha", "mayanka"};

 // for (int i : values)
 // {
 //  cout << i << endl;
 // }

 // what's happening under the hood?
 for (vector<int>::iterator i = values.begin(); i < values.end(); i++)
 {
  cout << *i << endl;
 }
 // unordered_set.find(): returns an iterator to element if found, otherwise returns an iterator to the end
 if (set.find("rohit") == set.end())
 {
  cout << "not found" << endl;
 }
 else
 {
  cout << *(set.find("rohit")) << endl;
 }
 // let's look at an iterator for unordered_set<string>, which is a more practical use of iterators
 for (unordered_set<string>::iterator i = set.begin(); i != set.end(); i++)
 {

  // IMPORTANT: here, i != set.end() works, but i < set.end() doesn't work. That's because unordered_set<string>::iterator isn't a random-access iterator!
  cout << *i << endl;
 }
 // types of iterators:
 // 1: input iterator
 // 2: output iterator
 // 3: forward iterator
 // 4: bidirectional iterator
 // 5: random-access iterator

 // input iterators: can only read, only accessing but not assigning
 // can deference
 // *i = 5 DOESN'T WORK
 // can only move in the forward direction
 // can only be accessed sequentially
 // can't go back either
 // suitable for input streams such as keyboard buffers or read-only files

 // output iterator: can only write, but not read
 // suitable to write only files
 // other properties same as input iterators

 // forward iterator: supports both read and write
 // sequential, can only move in forward direction
 // eg: simply linked list

 // bidirectional: forward iterator + can traverse backwards
 // i-- supported!
 // suitable for doubly linked list

 // random-access iterator: bidirectional + random_access by means of indexing
 // suitable for vectors and similar containers such as arrays

 // faster way of iterating through sets:
 cout << "----------" << endl;
 for (string x : set)
 {

  // internally:
  // for (unordered_set<string>::iterator i = set.begin(); i != set.end(); i++)
  // cout << *i << endl;
  cout << x << endl;
 }
 return 0;
}