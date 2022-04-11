#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();
    
    
    node* head1 = object.getHead();
    node* current = head1;
    node* copyN = NULL;
    object.remove(head1, head1, copyN, copyN, 2);

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    object.display();
    
    return 0;
}
