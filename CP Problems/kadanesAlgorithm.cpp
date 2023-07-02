//kadanesAlgorithm.cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
 int* input = new int[argc - 1];
 for (int i = 1; i < argc; i++) {
  input[i - 1] = stoi(argv[i]);
  // not derefence argv[i] as that would give us a single character
 }

 for (int i = 0; i < sizeof(input); i++) {
  std::cout
 }
 return -1;
}