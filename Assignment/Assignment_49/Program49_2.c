////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
//  Function Name   :   CheckAllPositive
//  Description     :   Used to Check all Elements are positive or not 
//  Input           :   Head
//  Output          :   BOOLEAN
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   31/12/2025
//
////////////////////////////////////////////////////////////////////////


bool CheckAllPositive(PNODE first)
{
    bool bFlag = true;
    
    if(first == NULL)
    {
        return;
    }

    while(first != NULL)
    {
        if(first-> data < 0)
        {
            bFlag = false;
            break;
        }
        first = first->next;
    }
    return bFlag;
}

////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////

int main()
{
    bool bRet = false;
    PNODE head = NULL;

    InsertFirst(&head, 99);
    InsertFirst(&head, -110);
    InsertFirst(&head, 100);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    bRet = CheckAllPositive(head);
    if(bRet == true)
    {
        printf("All are positive");
    }
    else
    {
        printf("One or more are non positive");
    }

    return 0;
}