#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
class Person
{

public:
 int age;
 string first_name;
 string last_name;

 Person(int age, const string &first_name, const string &last_name)
 {
  this->first_name = first_name;
  this->last_name = last_name;
 }
};

int main()
{
 Person p1(19, "Rohit", "Pokhrel");
 cout << p1.first_name << endl;
 cout << p1.last_name << endl;
 // the advantage with this is 
 if (p1.first_name >= p1.last_name)
 {
  cout << "here" << endl;
 }
 return 0;
}