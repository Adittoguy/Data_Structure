#include<iostream>
using namespace std;

#pragma pack(1)

class node
{
    public:
        int data;
        struct node * next;
        struct node * prev;

        node(int no)
        {
            data = no;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLLL
{
    public:
        node * first;
        int iCount = 0;

        DoublyLLL();
        
        void InsertFirst(int);
        void InsertLast(int);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int, int);
        void DeleteAtPos(int);
        void Display();
        int Count();
};

DoublyLLL :: DoublyLLL()
{}

void DoublyLLL :: InsertFirst(int no)
{}

void DoublyLLL :: InsertLast(int no)
{}

void DoublyLLL :: DeleteFirst()
{}

void DoublyLLL :: DeleteLast()
{}

void DoublyLLL :: InsertAtPos(int no, int pos)
{}

void DoublyLLL :: DeleteAtPos(int pos)
{}

void DoublyLLL :: Display()
{}

int DoublyLLL :: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////

int main()
{
    DoublyLLL * dobj = new DoublyLLL();

    return 0;
}