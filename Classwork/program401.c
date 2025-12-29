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
    PNODE temp = NULL;

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
        temp = *first;

        while(temp -> next != NULL)         // Type 2
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;                // $
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first) -> next;
        free(temp);

        (*first) -> prev = NULL;                // $
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteLast (PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp -> next -> next != NULL)         // type 3
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iCnt = 0;
    int iSize = 0;
    iSize = Count(*first);

    PNODE newn = NULL;
    PNODE temp = NULL;

    if((pos < 1) || (pos > iSize + 1))
    {
        printf("Invaild Position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE) malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteAtPos(PPNODE first, int pos)
{
    int iCnt = 0;
    int iSize = 0;
    iSize = Count(*first);

    PNODE temp = NULL;

    if((pos < 1) || (pos > iSize))
    {
        printf("Invaild Position");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

    }
}

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

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);

    iRet = Count(head);
    printf("Total nodes in linked list are: %d", iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);
    printf("Total nodes in linked list are: %d", iRet);

    DeleteLast(&head);

    Display(head);

    iRet = Count(head);
    printf("Total nodes in linked list are: %d", iRet);

    return 0;
}