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
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    T Value = 0;
    Queuenode<T> * temp = this->first;

    Value = this->first->data;

    if(this->first == this->last)
    {
        delete first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete temp;
    }

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

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while(1)                    // Unconditional loop
    {
        cout<<"---------------------------------------------------------------------------------------------------------\n";
        cout<<"--------------------------------------Please Select the Option-------------------------------------------\n";
        cout<<"1: Insert New element into the Queue\n";
        cout<<"2: Remove element from the Queue\n";
        cout<<"3: Display the Elements of the queue\n";
        cout<<"4: Count the number of elements from the Queue\n";
        cout<<"0: EXIT the Application\n";

        cin>>iChoice; 
        cout<<"---------------------------------------------------------------------------------------------------------\n";

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to insert: \n";
                cin>>Value;
                qobj->EnQueue(Value);
                cout<<"Element gets Inserted succussfully\n";
                break;
            
            case 2:
                iRet = qobj->DeQueue();
                if(iRet != -1)
                {
                    cout<<"Element Removed from queue : "<<iRet<<"\n";
                }
                break;

            case 3:
                cout<<"Elements of the queue are: \n";
                qobj->Display();
                break;

            case 4:
                iRet = qobj->Count();
                cout<<"Number of elements in queue are: "<<iRet<<"\n";
                break;
            
            case 0:
                cout<<"Thank you for using our application\n";
                delete qobj;
                return 0;

            default:
                cout<<"Please enter the valid option\n";

        }// End of switch

    }// End of while

    return 0;
}// End of Main