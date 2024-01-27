#include <string>
#include <stdio.h>
#include <iostream>
#include <mutex>

using namespace std;

int main() {

 mutex stringMutex;
 string x = "rohit";


 for (int i = 0; i < x.size(); i++) {
  if (stringMutex.try_lock()) {
   stringMutex.lock();
   x[0] = '1';
   stringMutex.unlock();
  }  
 }

 cout << x << endl;
}