#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();
    node* head1 = object.getHead();
    node* current = head1;
    object.remove(current,9);

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    object.display();
    
    return 0;
}
