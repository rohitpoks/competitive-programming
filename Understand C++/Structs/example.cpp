#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// assume max dimensions is 3
struct Vector
{
 int dim;
 int elements[3];

 Vector(int x, int y, int z)
 {
  elements[0] = x;
  elements[1] = y;
  elements[2] = z;

  dim = 3;
 }

 Vector(int x, int y)
 {
  Vector(x, y, 0);
  dim = 2;
 }

 void add(Vector &v)
 {
  if (v.dim != this->dim)
  {
   cout << "can't add, wrong dimensions\n";
   return;
  }
  for (int i = 0; i < dim; i++)
  {
   elements[i] += v.elements[i];
  }
 }
};

int main()
{

 // important example: this is how you can provide arguments :)

 struct second_vector
 {
  second_vector(){

  }
  second_vector(int k)
  {
   k++;
  }
  int x;
  int y;
 } v2(5);

 v2.x = 3;
 cout << v2.x;
 struct Vector a(0, 1, 2);
 struct Vector b(0, 2, 3);
 a.add(b);
 return 0;
}