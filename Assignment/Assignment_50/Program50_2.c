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
//  Function Name   :   DisplayGreaterThanAvg
//  Description     :   Used to Display numbers greater than average
//  Input           :   Head
//  Output          :   Elements greater than average
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   1/1/2026
//
////////////////////////////////////////////////////////////////////////


void DisplayGreaterThanAvg(PNODE first)
{
    int iSum = 0;
    int iAvg = 0;
    int iCount = 0;
    PNODE temp = NULL;

    if(first == NULL)
    {
        return;
    }

    temp = first;
    while(temp != NULL)
    {
        iSum += temp->data;
        temp = temp->next;
        iCount++;
    }

    iAvg = iSum/iCount;

    temp = first;
    while(temp != NULL)
    {
        if(temp->data > iAvg)
        {
            printf("| %d | ", temp->data);
        }
        temp = temp->next;
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

    InsertFirst(&head, 99);
    InsertFirst(&head, 110);
    InsertFirst(&head, -100);
    InsertFirst(&head, 51);
    InsertFirst(&head, -21);
    InsertFirst(&head, 11);

    Display(head);

    DisplayGreaterThanAvg(head);

    return 0;
}