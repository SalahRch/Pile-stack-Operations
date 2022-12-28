//
// Created by Salahrch on 28/12/2022.
//
/* Queue/File -> FIFO: First in first out*/
#ifndef Files_h
#define Files_h
#include <stdlib.h>
#include <stdio.h>


typedef struct File{
    int value;
    struct File *next;
}File;

//Possible operations we can do on a queue?
//1- Enqueue: Add an element to the queue
//2- Dequeue: Remove an element from the queue
//3- Peek: Get the first element of the queue
//4- isEmpty: Check if the queue is empty
//5- printQueue: Print the queue

//1- Enqueue: Add an element to the queue
void Enqueue(File **head,File **tail,int value){
    File *new=(File*)malloc(sizeof(File));
    new->next=NULL;
    new->value=value;
    if((*head)==NULL && (*tail) ==NULL){
        (*head)=(*tail)=new;
        printf("Pushed value %d succefully in the queue !\n",new->value);
        return;
    }
    else {
        (*tail)->next = new;
        (*tail) = new;
        printf("Pushed value %d succefully in the queue !\n", new->value);
    }
}

//2- Dequeue: Remove an element from the queue
void Dequeue(File **head,File **tail){
    File *temp=*head;
    if((*head)==NULL){
        printf("Queue already empty!\n");
    }
    else if((*head)==(*tail)){
        (*head)=NULL;
        (*tail)=NULL;
    }
    else (*head) = (*head)->next;

    printf("Dequeued value %d from Queue successfully!\n", temp->value);
    free(temp);
}

//3- Peek: Get the first element of the queue
int peek(File *head){
    if(head==NULL){
        printf("No peek value, queue is empty\n");
        return -1;
    }
    return head->value;
}

//4- isEmpty: Check if the queue is empty
int isEmpty(File *head){
    return head==NULL;
}

//5- printQueue: Print the queue
void printQueue(File *head){
    if(head==NULL){
        printf("Queue is empty!\n");
        return;
    }
    else {
        while (head != NULL) {
            printf("%d -> ", head->value);
            head = head->next;
        }
    }
    printf("NULL \n");
}



#endif //Files_h
