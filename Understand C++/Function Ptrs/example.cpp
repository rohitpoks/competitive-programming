#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int *c = (int *)malloc(sizeof(int));
int *exampleFunction(int a, int b)
{
 *c = (a + b);
 return c;
}

int main()
{
 int *(*example)(int x, int y);
 // exampleFunction(5, 3);
 example = exampleFunction;
 cout << *example(2, 3) << endl;
 free(c);
 return 0;
}