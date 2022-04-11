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

void remove(node* &head, node* previous, node* current, int number)
{
  if (head->data == number)
    {
      node* temp = head;
      head = head->next;
      delete temp;
      remove(head, head, head->next, number);
    }
  else
    {
      if (current!= NULL)
	{
	  if (current->data == number)
	    {
	      node* temp = current;
	      previous->next = current->next;
	      current = previous->next;
	      delete temp;
	      remove(head, previous, current, number);
	    }
	  else
	    {
	      previous = current;
	      current = current->next;
	      remove(head, previous, current, number);
	    }
	}
    }
  
}

node* dlist::getHead()
{
  return head;
}
