#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
class Person
{

public:
 int age;
 char first_name[100];
 char last_name[100];

 Person(int age, char first_name[], char last_name[])
 {
  this->age = age;
  // the following statements don't work, as arrays are not modifiable l-values

  // this->first_name = first_name;
  // this->last_name = last_name;

  // so, we'll have to use strcpy here

  strcpy(this->first_name, first_name);
  strcpy(this->last_name, last_name);

  // however, this is allowed:
  // char temp[] = "Rohit";
  // adds null byte at the end
  // we can't reassign temp though
 }

 Person(const Person &P)
 {
  strcpy(this->first_name, P.first_name);
  strcpy(this->last_name, P.last_name);
 }
};

int main()
{
 char first_name[] = "Rohit";
 // automatically adds null character at the end
 // cout << sizeof(first_name) returns 6
 char last_name[] = "Pokhrel";

 // // however, the disadvantage of using char arrays is standard c++ operators can't be used

 // if (first_name < last_name)
 // {
 //  cout << "True\n";
 // }
 Person p1(19, first_name, last_name);
 Person p2(p1);
 cout << p2.last_name << endl;
 return 0;
}