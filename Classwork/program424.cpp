#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node* PNODE;

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

        void InsertFirst(int no)        // Updated
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = first;

            first = newn;

            iCount++;
        }
        
        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                temp -> next = newn;
            }

            iCount++;
        }

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void InsertAtPos(int no, int pos)
        {}

        void DeleteAtPos(int pos)
        {}

        void Display()
        {
            PNODE temp = NULL;

            temp = first;

            while(temp != NULL)
            {
                cout << "| "<< temp -> data << " |-->";
                temp = temp -> next;
            }
            cout << "NULL\n";
        }

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

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    return 0;
}