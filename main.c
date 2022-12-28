#include <stdio.h>
#include "Piles.h"
/* Stack -> LIFO: Last in first out
   Created : 28/12/2022  */

int main() {
    Pile *head=NULL;
    push(&head,1);
    push(&head,3);
    push(&head,6);
    pop(&head);
    printf("The peek of this stack is: %d\n",peek(head));
    if(isEmpty(head))
        printf("The stack is empty\n");
    else
        printf("The stack is not empty\n");
    printPile(head);
    return 0;
}


/* Salaheddine Rouchdi */