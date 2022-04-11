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

void dlist::remove2(node* current, int th){
     if(current == head){
     	cout << "hi" << endl;
	node* temp = head;
	head = head -> next;
	head -> previous = NULL;
	current = head;
	delete temp;
	current = current -> next;
        remove2(current, th);
     }
	if(current != head && current -> next != NULL){
        cout << "none" << endl;
	current = current -> next;
     	remove2(current, th);
}

}


void dlist::remove(node* current, int newData)
{
  if (head->data >= newData)
    {
      node* temp = head;
      head = head->next;
      delete temp;
      head->previous = NULL;
      current = head;
      remove(current, newData);
    }
  else
    {
      if (current != tail)
	{
	  if (current->data >= newData)
	    {
	      node* temp = current;
	      node* pre = current->previous;
	      pre->next = current->next;
	      current = current->next;
	      current->previous = pre;
	      delete temp;
	      remove(current, newData);
	    }
	  else
	    {
	      current = current->next;
	      remove(current, newData);
	    }
	}
      else
	{
	  if (tail->data >= newData)
	    {
	      node* temp = current;
	      node* pre = current->previous;
	      pre->next = NULL;
	      tail = pre;
	      delete temp;
	    }
	}
    }
}

node* dlist::getHead()
{
  return head;
}
