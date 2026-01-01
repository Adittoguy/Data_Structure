////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include<stdlib.h>

#pragma pack(1)

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
//  Date          : 31/12/2025
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
        newn -> next = *first;
        *first = newn;
    }
}   

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |-->", first-> data);
        first = first -> next; 
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   ReplaceEven
//  Description     :   Used to replace all Even elements to 0
//  Input           :   &Head
//  Output          :   Even -> 0
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   31/12/2025
//
////////////////////////////////////////////////////////////////////////


void ReplaceEven(PPNODE first)
{
    PNODE temp = NULL;
    
    if((first == NULL) || (*first == NULL))
    {
        return;
    }

    temp = *first;

    while(temp != NULL)
    {
        if((temp -> data % 2)== 0)
        {
            temp -> data = 0;
        }
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
    PNODE head = NULL;

    InsertFirst(&head, 999);
    InsertFirst(&head, 110);
    InsertFirst(&head, 100);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    ReplaceEven(&head);

    Display(head);

    return 0;
}