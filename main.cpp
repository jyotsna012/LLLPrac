#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();
    node* current = head;
    object.remove(current, 9);

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    object.display();
    
    return 0;
}
