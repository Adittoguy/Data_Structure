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
//  Function Name   :   SecMaximum
//  Description     :   Used to find second maximum numbers from linked list
//  Input           :   Head
//  Output          :   Integer(Second Maximum among Elements)
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   17/12/2025
//
////////////////////////////////////////////////////////////////////////

int SecMaximum(PNODE Head)
{
    PNODE iCnt = Head;
    int iMax = Head -> Data;
    int iSecMax = Head -> Data;

    while(iCnt != NULL)
    {
        if(iMax < (iCnt -> Data))
        {
            iSecMax = iMax;
            iMax = iCnt -> Data; 
        }
        else if(iCnt -> Data > iSecMax && iCnt -> Data != iMax)
        {
            iSecMax = iCnt -> Data;
        }

        iCnt = iCnt -> Next;
    }

    return iSecMax;
}

////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;

    PNODE First = NULL;

    InsertFirst(&First, 5);
    InsertFirst(&First, 111);
    InsertFirst(&First, 6);
    InsertFirst(&First, 101);
    InsertFirst(&First, 28);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    iRet = SecMaximum(First);

    printf("Second Maximum among all Numbers is: %d", iRet);

    return 0;
}
