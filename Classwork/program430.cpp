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
            this -> first = NULL;
            this -> iCount = 0;
        }

        void InsertFirst(int no)        // Updated
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = this -> first;

            this -> first = newn;

            this -> iCount++;
        }
        
        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if(this -> iCount == 0)
            {
                this -> first = newn;
            }
            else
            {
                temp = this -> first;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }
                temp -> next = newn;
            }

            this -> iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this -> first == NULL)
            {
                return;
            }
            else if(this -> first -> next == NULL)  // else if(this -> iCount == 1)
            {
                delete this -> first;
                this -> first = NULL;
            }
            else
            {
                temp = this -> first;
                this -> first = first -> next;
                delete temp;
            }
            this -> iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(this -> first == NULL)
            {
                return;
            }
            else if(this -> first -> next == NULL)  // else if(this -> iCount == 1)
            {
                delete this -> first;
                this -> first = NULL;
            }
            else
            {
                temp = this -> first;

                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                delete temp -> next;
                temp -> next = NULL;
            }
            this -> iCount--;
        }

        void Display()
        {
            int iCnt = 0;
            PNODE temp = NULL;

            temp = this -> first;

            for(iCnt = 1; iCnt <= this -> iCount; iCnt++)           // Updated (new method)
            {
                cout << "| "<< temp -> data << " |-->";
                temp = temp -> next;
            }

            cout << "NULL\n";
        }

        int Count()
        {
            return this -> iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;
    
            PNODE newn = NULL;
            PNODE temp = NULL;

            if((pos < 1) || (pos > this -> iCount + 1))
            {
                cout << "Invalid Position";
                return;
            }

            if(pos == 1)
            {
                this -> InsertFirst(no);
            }
            else if(pos == this -> iCount + 1)
            {
                this -> InsertLast(no);
            }
            else
            {
                temp = this -> first;

                newn = new NODE;

                newn -> data = no;
                newn ->  next = NULL;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }
                newn -> next = temp -> next;
                temp -> next = newn;

                this -> iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;
            PNODE temp = NULL;
            PNODE target = NULL;

            if((pos < 1) || (pos > this -> iCount))
            {
                cout << "Invalid Position";
                return;
            }

            if(pos == 1)
            {
                this -> DeleteFirst();
            }
            else if(pos == this -> iCount)
            {
                this -> DeleteLast();
            }
            else
            {
                temp = this -> first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }
                target = temp -> next;
                temp -> next = target -> next;
                delete target;

                this -> iCount--;
            }   
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

    // obj.first = NULL; RISKY SYNTAX
    // obj.Count = 0;

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