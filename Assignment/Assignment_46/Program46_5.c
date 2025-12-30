////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

/*------------------------------------------------------------------------------
        Old Name                    New Name
--------------------------------------------------------------------------------
        struct Node                 NODE
        struct Node *               PNODE
        struct Node **              PPNODE
--------------------------------------------------------------------------------*/

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at first position
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;
    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = (*first);
        *first = newn;
    }
}



void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |-->", first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   IncrementAll
//  Description     :   Used to Increase all elements from list by 1 
//  Input           :   &Head
//  Output          :   -1 -> 0
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   30/12/2025
//
////////////////////////////////////////////////////////////////////////

void IncrementAll(PPNODE first)
{
    PNODE temp = NULL;
    temp = *first;

    while(temp != NULL)
    {
        temp -> data++;
        temp = temp -> next;
    }
}

////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////

int main()
{
    bool bRet = false;
    PNODE head  = NULL;

    InsertFirst(&head, 62);
    InsertFirst(&head, -54);
    InsertFirst(&head, 0);
    InsertFirst(&head, 51);
    InsertFirst(&head, -21);
    InsertFirst(&head, 11);

    Display(head);

    IncrementAll(&head);

    Display(head);

    return 0;
}