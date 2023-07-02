#include <iostream>
#include <stdio.h>
using namespace std;


class LinkedList {

 public:

 int val;
 LinkedList* next;


 LinkedList(int val) {
  this->val = val;
  this->next = NULL;
 }

 ~LinkedList() {
  // free(this);
 }

};

int main() {
 LinkedList* head = new LinkedList(-1);
 LinkedList* current = head;
 for (int i = 0; i < 10; i++) {
  (*current).next = new LinkedList(i);
  // points currently to current, derefence it to get to next which is a pointer, then make the pointer point to a new linkedlist
  current = (*current).next;
 }
 current = head;
 // *current.val won't work as . is processed first
 for (int i = 0; i < 10; i++) {
  cout << (*current).val << " ";
  current = (*current).next;
 }
 


 current = head;
 LinkedList* next = (*current).next;
 for (int i = 0; i < 11; i++) {
  next = (*current).next;
  delete current;
  current = next;
 }
 cout << "\nDONE\n";
}


