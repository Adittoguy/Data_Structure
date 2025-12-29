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

            if(iCount == 0)
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
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)  // else if(iCount == 1)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;
                first = first -> next;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)  // else if(iCount == 1)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                delete temp -> next;
                temp -> next = NULL;
            }
            iCount--;
        }

        void InsertAtPos(int no, int pos)
        {}

        void DeleteAtPos(int pos)
        {}

        void Display()
        {
            int iCnt = 0;
            PNODE temp = NULL;

            temp = first;

            for(iCnt = 1; iCnt <= iCount; iCnt++)           // Updated (new method)
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

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout << "Total nodes are: "<< iRet << "\n";

    return 0;
}