// SINGLY CIRCULAR

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    private: 
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL()
        {
            cout << "Object of SinglyCL get created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn  = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                newn -> next = this->first;
                this->first = newn;
            }
            this->iCount++;
            (this->last) -> next = this->first;
        }
        
        void InsertLast(int no)
        {
            PNODE newn  = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                this->first = newn;
                this->last = newn;
            }
            else
            {
                temp = this->first;

                this->last -> next = newn;
                this->last = newn;

            }
            this->iCount++;
            (this->last) -> next = this->first;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                return;
            }
            else if(this->first == this->last)
            {
                free(this->first);
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;
                this->first = this->first -> next;
                free(temp);
            }
            this->iCount--;
            this->last -> next = this->first;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if((this->first == NULL) && (this->last == NULL))
            {
                return;
            }
            else if(this->first == this->last)
            {
                free(this->first);
                this->first = NULL;
                this->last = NULL;
            }
            else
            {
                temp = this->first;

                while(temp -> next != this->last)
                {
                    temp = temp -> next;
                }
                free(this->last);
                this->last = temp; 
            }
            this->iCount--;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;
            PNODE newn = NULL;
            PNODE temp = NULL;

            if(pos > this->iCount + 1 || pos < 0)
            {
                cout << " Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                this->InsertFirst(no);
            }
            else if(pos == this->iCount + 1)
            {
                this->InsertLast(no);
            }
            else
            {
                temp = this->first;
                newn = new NODE;

                newn -> data = no;
                newn -> next = NULL;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }
                newn -> next = temp -> next;
                temp -> next = newn;

                this->iCount++;
                this->last -> next = this->first;
            }
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;
            PNODE temp = NULL;
            PNODE target = NULL;

            if(pos > iCount || pos < 0)
            {
                cout << " Invalid position\n";
                return;
            }

            if(pos == 1)
            {
               this->DeleteFirst();
            }
            else if(pos == this->iCount)
            {
                this->DeleteLast();
            }
            else
            {
                temp = this->first;
                
                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }
                target = temp-> next;
                temp -> next = target -> next;
                free(target);

                this->iCount--;
                this->last -> next = this->first;
            }
        }

        void Display()
        {
            int iCnt = 0;
            PNODE temp = NULL;
            temp = this -> first;

            for(iCnt = 1; iCnt <= this->iCount; iCnt++)
            {
                cout<<"| "<<temp -> data<<" |-->";
                temp = temp -> next;
            }
            cout << "NULL\n";
        }

        int Count()
        {
            return this->iCount;
        }

};

int main()
{
    int iRet = 0;

    SinglyCL obj;

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