#ifndef PRO_LAB4_QUEUE_H
#define PRO_LAB4_QUEUE_H

#include "base.h"

typedef struct node_t
{
    int data;
    struct node_t* next;
}  TNode;

//queue
struct node_t* head=NULL;
struct node_t* tail=NULL;


void PushQue(int dataParam)
{
    struct node_t*  p = (struct node_t*)malloc(sizeof(struct node_t));
    p->next = NULL;

    if (head == NULL) {
        p->data = 0;
        head = p;
    }
    else {
        p->data = dataParam;
        tail->next = p;
    }
    tail = p;
}

void* PopQue()
{
    void* p = NULL;
    p = head;
    head = head->next;
    return p;
}

int EmptyQue(){
    return head == NULL;
}

int FullQue(){
    if(EmptyQue()) return 0;
    return max_queue_length < tail->data;
}

void PrintQue()
{
    struct node_t*  p = head;
    while( p != NULL){
         printf("%d ",p->data);
         p = p->next;

    }
}


#endif //PRO_LAB4_QUEUE_H
