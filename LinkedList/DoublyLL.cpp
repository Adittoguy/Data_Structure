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
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;
            
            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn -> next = first;
                first -> prev = newn;
                first= newn;
            }
            iCount++;
        }
        
        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            
            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

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
                newn -> prev = temp;
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
            else if(first -> next == NULL)
            {
                free(first);
                first = NULL;
            }
            else
            {
                temp = first;
                first = first -> next;
                free(temp);

                first -> prev = NULL;
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
            else if(first -> next == NULL)
            {
                free(first);
                first = NULL;
            }
            else
            {
                temp = first;
                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                free(temp-> next);
                temp -> next = NULL;
            }
            iCount--;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE newn = NULL;

            if(pos > iCount + 1 || pos < 0)
            {
                cout << "Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                temp = first;

                newn = new NODE;
                newn -> data = no;
                newn -> next = NULL;
                newn -> prev = NULL;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }
                newn -> next = temp -> next;
                temp -> next -> prev = newn;
                temp -> next = newn;
                newn -> prev = temp;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            if(pos > iCount || pos < 0)
            {
                cout << "Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {   
                temp = first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }
                target = temp -> next;
                temp -> next = target -> next;
                temp -> next -> prev = temp;
                free(target);

                iCount--;
            }
        }

        void Display()
        {
            int iCnt = 0;
            PNODE temp = NULL;

            temp = first;

            for(iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout << "| "<<temp->data<<" |<==>";
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