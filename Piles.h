//
// Created by Salahrch on 28/12/2022.
//
/* Stack -> LIFO: Last in first out*/
#ifndef Piles_h
#define Piles_h
typedef struct Pile{
    int value;
    struct Pile *next;
}Pile;
//possible operations we can do with stack ?
void push(Pile **p,int value){
    Pile *new=(Pile*)malloc(sizeof(Pile));
    new->value=value;
    new->next = NULL;
    if(p==NULL){
        (*p)=new;
        printf("Pushed %d successfully!\n",value);
        return;
    }
    new->next = (*p);
    (*p)=new;
    printf("Pushed %d successfully!\n",value);
}
int pop(Pile **p){
    if(p==NULL){
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
int peek(Pile *p){
    if(p==NULL){
        printf("Stack is empty!\n");
        return -1;
    }
    return p->value;
}
int isEmpty(Pile *p){
    return p==NULL;
}
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
