#include "dlist.h"

dlist::dlist() {
  head = NULL;
  tail = NULL;
}

dlist::~dlist() {
  while (head != NULL) {
    node* temp = head;
    head = head->next;
    delete temp;
  }
}

void dlist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  head = current;
  current->previous = NULL;
  node* previous = current;
  int additionalValues = (rand()&5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->previous = previous;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  tail = current;
  current->next = NULL;
}

void dlist::display() {
  node* current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void dlist::remove(node* &head, node* current, int th, int &a){
  a++;
  cout << current->data << endl;
  if(current->next == NULL){
    if(current->data > th){
      current->previous = current-> next;
    }
    return;
  }
  current = current -> next;
  remove(head, current, th);
  if(current->data >= th){
    cout << "over 5: " << current-> data << endl;
      if(current -> next== NULL){
        cout<< "tail: "  << current-> data <<endl;
        current -> previous -> next == NULL;
      }
      else{
        current->previous->next= current-> next;
      }
    }
}

node* dlist::getHead()
{
  return head;
}
