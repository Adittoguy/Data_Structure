#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void Display(PNODE first, PNODE last)
{
    printf("\n ->");                            // connected from last to first
    do{
        printf("| %d |-->", first -> data);
        first = first -> next;
    }while(first != last -> next);
    printf("\n");
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do{
        iCount++;
        first = first -> next;
    }while(first != last -> next);

    return iCount;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL))         // @
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }

    (*last) -> next = *first;                       // @

}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc (sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn;                     // @
        *last = newn;                               // @
    }

    (*last) -> next = *first;                       // @
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))         // CASE 1
    {
        return;
    }
    else if(*first == *last)                        // CASE 2
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                            // CASE 1
    {
        temp = *first;
        *first = (*first) -> next;                  // temp -> next :similar to this condition
        free(temp);
    }
    (*last) -> next = *first;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))         // CASE 1
    {
        return;
    }
    else if(*first == *last)                        // CASE 2
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                            // CASE 1
    {
        temp = *first;

        while(temp -> next != *last)
        {
            temp = temp -> next;
        }
        free(*last);
        *last = temp;
    }
    (*last) -> next = *first;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    int iCount = 0;
    int iCnt = 0;
    iCount = Count(*first, *last);

    PNODE newn = NULL;
    PNODE temp = NULL;

    if((pos > iCount + 1) || (pos < 0))
    {
        printf("Invalid Position\n");
        return ;
    }

    if(pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        temp = *first;

        newn = (PNODE) malloc (sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;    
        }
        newn->next = temp -> next;
        temp -> next = newn;
    }
    (*last) -> next = (*first);

}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int iCount = Count(*first, *last);

    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0;

    if((pos > iCount) || (pos < 0))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos > iCount)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next; 
        free(target);
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    int iRet = 0;
    PNODE head = NULL;
    PNODE tail = NULL;      // @

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 121);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of nodes: %d\n", iRet);

    DeleteFirst(&head, &tail);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of nodes: %d\n", iRet);

    DeleteLast(&head, &tail);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of nodes: %d\n", iRet);

    InsertAtPos(&head, &tail, 105, 3);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of nodes: %d\n", iRet);

    DeleteAtPos(&head, &tail, 3);

    Display(head, tail);

    iRet = Count(head, tail);
    printf("Number of nodes: %d\n", iRet);

    return 0;
}