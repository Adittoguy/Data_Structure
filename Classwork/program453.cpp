// DOUBLY LINEAR

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private: 
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout << "Object of DoublyLL get created.\n";
            this->first = NULL;
            this->iCount = 0;
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

    DoublyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj.InsertAtPos(105, 4);

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    return 0;
}