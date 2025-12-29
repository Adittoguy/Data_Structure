#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
    public: 
        PNODE first;
        int iCount;

        SinglyLL()
        {
            cout << "Object of SinglyLL get created.\n";
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {}
        
        void InsertLast(int no)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void InsertAtPos(int no, int pos)
        {}

        void DeleteAtPos(int pos)
        {}

        void Display()
        {}

        int Count()
        {
            return iCount;
        }

};

int main()
{
    int iRet = 0;

    SinglyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    return 0;
}