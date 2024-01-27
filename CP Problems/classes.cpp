#include <iostream>

using namespace std;
class Animal {
 public:
 virtual string sound() {
  return "zz";
 }
};

class Dog : private Animal {
 
};