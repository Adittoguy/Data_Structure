////////////////////////////////////////////////////////////////////
// Final Code of Queue Using Generic apporach
////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;

    public:
        Queue();

        void EnQueue(T);    
        T DeQueue();          
        void Display();
        int Count();
};

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue is Created...\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
void Queue<T> :: EnQueue(T no)
{
    Queuenode<T> * newn = NULL;
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;      // this->last = newn;
    }

    this->iCount++;
}

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
T Queue<T> :: DeQueue()
{
    T Value = 0;
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |--";
        temp = temp -> next;
    }
    cout<<"\n";
}

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////

int main()
{
    Queue<int>* qobj = new Queue<int>();

    qobj->EnQueue(11);
    qobj->EnQueue(21);
    qobj->EnQueue(51);
    qobj->EnQueue(101);

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    cout<<"Removed ELement is : "<<qobj->DeQueue()<<"\n";

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    cout<<"Removed ELement is : "<<qobj->DeQueue()<<"\n";

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    qobj->EnQueue(121);

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}