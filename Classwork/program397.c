#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node * next;
    struct node * prev;                 // $
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void Display(PNODE first)
{
    printf("\nNULL<==>");
    while(first != NULL)
    {
        printf("| %d |<==>", first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;                    // $

    if(*first == NULL)
    {
        *first = newn; 
    }
    else
    {
        newn -> next = *first;
        (*first) -> prev = newn;            // $
        *first = newn;
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;                    // $

    if(*first == NULL)
    {
        *first = newn; 
    }
    else
    {
        
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteFirst(PPNODE first)
{}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteLast (PPNODE first)
{}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void InsertAtPos(PPNODE first, int no, int pos)
{}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteAtPos(PPNODE first, int pos)
{}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = Count(head);
    printf("Total nodes in linked list are: %d", iRet);

    return 0;
}