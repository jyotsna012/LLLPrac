#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();
    node* head1 = object.getHead();
    node* current = head1;
    object.remove(head1, current,5,0);

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    object.display();
    
    return 0;
}
