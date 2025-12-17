////////////////////////////////////////////////////////////////////////
//
//  Required Header Files
//
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    struct node* Next;
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
//  Date          : 17/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Next = NULL;
    newn -> Data = no;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> Next = *Head;
        *Head = newn;
    }
}

////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   SumDigit
//  Description     :   Used to print sum of all digits of all numbers persent in linked list
//  Input           :   Head
//  Output          :   Integer(Sum of digit)
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   17/12/2025
//
////////////////////////////////////////////////////////////////////////

int SumDigit(PNODE Head)
{
    PNODE iCnt = Head;
    int iDigit = 0;
    int iSum = 0;
    
    while(iCnt != NULL)
    {
        iDigit = 0;
        iSum = 0;

        while(iCnt -> Data != 0)
        {
            iDigit = (iCnt->Data) % 10;
            iSum = iSum + iDigit;
            iCnt -> Data /= 10; 
        }
        printf("%d\t", iSum);

        iCnt = iCnt -> Next;
    }
}

////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 5);
    InsertFirst(&First, 111);
    InsertFirst(&First, 6);
    InsertFirst(&First, 101);
    InsertFirst(&First, 28);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    SumDigit(First);

    return 0;
}
