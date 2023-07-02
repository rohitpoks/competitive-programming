#include <iostream>
// copies a file iostream, literally copies the file into your .cpp file
using namespace std;

int main(int argc, char* argv[]) {
 // insertion operator, writing to the stream using <<
 cout << "Hello world\n";
 // insertion operator << insert, writes to an output stream
 // pointing away from the stream towards the variables >> 
 // computers deal with memory
 // memory is everything
 // pointers are extremely important for managing memory
 // stores memory address
 // memory: linear street, houses on a street on just one side
 // where that house is: address
 // a pointer is just an address!
 // doesn't matter what pointer you have, what type
 int var = 8;
 // ptr is currently not valid
 
 int* ptr = &var;
 // types are useful for manipulation of memory
 // *ptr = 10;, not gonna work if prt is void because is 10 an integer? it is a long? is it a short-byte integer?

 char* buffer = new char[8]; // new and delete, new for asking for new memory, delete for deleting from memory
 // allocate memory so that 8 chars can fit in, initially buffer points to the first character in memory
 for (int i = 0; i < 20; i++) {
  *buffer = 'A' + i;
  cout << buffer;
  buffer++;
 }
 // why does this work?
 delete[] buffer;
// difference between
 char** pointerToBuffer = nullptr;
 *pointerToBuffer = buffer;
 // and
 char** pointerToBuffer2 = &buffer;

 // pointers and references are pretty much the same thing
 // references are just pointers in disguise
 // a reference is the reference to an existing variable
 // references: not new variable, they are a reference to a variable

 int a = 2;
 int& ref = a;
 // now, ref is a, if you change ref, you change a
 // but you don't have to dereference it each time
 ref = 3;
 // but *ref = 2 wouldn't work
 
}


void increment(int* val) {
 (*val)++; 
 // derefence value and then increase it
}

// but instead of doing this, just use the & operator
// passing by reference
void incrementEasily(int& ref) {
 ref++;
}
