#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
}; // NODE, *PNODE, **PPNODE;       // Internal typedef 

typedef struct node NODE;           // External typedef
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;
    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)              // LinkedList is empty
    {
        (*first) = newn;
    }   
    else                            // LinkedList contains atleast one node
    {
        newn -> next = (*first);
        (*first) = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)              // LinkedList is empty
    {
        *first = newn;
    }   
    else                            // LinkedList contains atleast one node
    {
        
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    return 0;
}