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
//  Function Name   :   SumDigits
//  Description     :   Used to find sum of digits in the elements
//  Input           :   Head
//  Output          :   Sum of each element
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   31/12/2025
//
////////////////////////////////////////////////////////////////////////


void SumDigits(PNODE first)
{
    while(first != NULL)
    {
        int iSum = 0;
        int iDigit = 0;

        while(first->data != 0)
        {
            iDigit = first->data % 10;
            iSum = iSum + iDigit;
            first->data /= 10;
        }
        printf("| %d |-",iSum);
        first = first -> next;
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
    InsertFirst(&head, 111);
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    SumDigits(head);

    return 0;
}