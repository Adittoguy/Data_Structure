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
//  Function Name   :   DisplayPerfect
//  Description     :   Used to print all the perfect numbers from linked list
//  Input           :   Head
//  Output          :   Integer(Prefect numbers)
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   17/12/2025
//
////////////////////////////////////////////////////////////////////////

void DisplayPerfect(PNODE Head)
{
    PNODE iCnt = Head;
    int i = 0;

    while(iCnt != NULL)
    {
        int iSum = 0;

        for(i = 1; i <= (iCnt -> Data)/2; i++)
        {
            if((iCnt-> Data % i)==0)
            {
                iSum += i;
            }
        }

        if(iSum == iCnt->Data && iCnt != 0)
        {
            printf("%d\t",iCnt->Data);
        }

        iCnt = iCnt -> Next;
    }
    printf("\n");
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

    DisplayPerfect(First);

    return 0;
}
