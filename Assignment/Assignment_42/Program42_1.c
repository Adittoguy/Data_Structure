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
//  Function Name   :   SearchFirstOcc
//  Description     :   Used to Find the first occurance of element in list
//  Input           :   Head, value to find
//  Output          :   Index value(Integer)
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   17/12/2025
//
////////////////////////////////////////////////////////////////////////

int SearchFirstOcc(PNODE Head, int no)
{
    PNODE iCnt = Head;
    int index = 1;

    while(iCnt != NULL)
    {
        if(iCnt -> Data == no)
        {
            return index;
        }
        index++;
        iCnt = iCnt -> Next;
    }

    return -1;
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

    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    iRet = SearchFirstOcc(First, 111);

    printf("Position of element is: %d\n", iRet);

    return 0;
}
