//
// Created by Salahrch on 28/12/2022.
//
/* Stack -> LIFO: Last in first out*/
#ifndef Piles_h
#define Piles_h
#include <stdlib.h>
#include <stdio.h>



typedef struct Pile{
    int value;
    struct Pile *next;
}Pile;
//possible operations we can do with stack ?

//to push an element in the stack (empiler)
void push(Pile **p,int value){
    Pile *new=(Pile*)malloc(sizeof(Pile));
    new->value=value;
    new->next = NULL;
    if((*p)==NULL){
        (*p)=new;
        printf("Pushed %d successfully!\n",value);
        return;
    }
    new->next = (*p);
    (*p)=new;
    printf("Pushed %d successfully!\n",value);
}

//to pop an element outside the stack (dépiler)
int pop(Pile **p){
    if((*p)==NULL){
        printf("Impossible to pop something, stack empty!\n");
        return -1;
    }
    int value;
    value = (*p)->value;
    Pile *temp = (*p);
    (*p)=(*p)->next;
    free(temp);
    printf("Value %d popped succesfully!\n",value);
    return value;
}

//to see the peek element of the stack (sommet)
int peek(Pile *p){
    if(p==NULL){
        printf("Stack is empty!\n");
        return -1;
    }
    return p->value;
}

//to check if Stack is empty (returns boolean value)
int isEmpty(Pile *p){
    return p==NULL;
}

//to print the elements of a stack
void printPile(Pile *p){
    if(p==NULL){
        printf("Stack is empty!\n");
        return;
    }
    while(p!=NULL){
        printf("%d -> ",p->value);
        p=p->next;
    }
    printf("NULL \n");
}

#endif //Piles_h