//////////////////////////////////////////////
// Generalised Data Structure Library
//////////////////////////////////////////////

/*--------------------------------------------------------------------------------------------------------------
Type                    Name of Class For Node                              Name of Class for Functionality
----------------------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                                       SinglyLLL          Done
Singly Circular         SinglyCLLnode                                       SinglyCLL  
Doubly Linear           DoublyLLLnode                                       DoublyLLL          Done
Doubly Circular         DoublyCLLnode                                       DoublyCLL
Stack                   Stacknode                                           Stack              Done
Queue                   Queuenode                                           Queue              Done
----------------------------------------------------------------------------------------------------------------*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//                        Singly Linear Linked list Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:                //  IMPORTANT
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);        // Updated
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout << "Object of SinglyLLL get created.\n";
    this -> first = NULL;
    this -> iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Description     :   Used to Insert Node at First Position
//  Input           :   Data Of Node
//  Output          :   Nothing
//  Author          :   Aditya Bhaskar Sanap
//  Date            :   06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>:: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn -> next = this -> first;
    this -> first = newn;

    this -> iCount++;
}

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

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

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

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

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

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

template <class T>
void SinglyLLL<T> :: Display()
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;

    temp = this -> first;

    for(iCnt = 1; iCnt <= this -> iCount; iCnt++)           // Updated (new method)
    {
        cout << "| "<< temp -> data << " |-->";
        temp = temp -> next;
    }

    cout << "NULL\n";
}

template <class T>
int SinglyLLL<T> :: Count()
{
    return this -> iCount;
}

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;

    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

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

        newn = new SinglyLLLnode<T>(no);

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;

        this -> iCount++;
    }
}

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//                        Doubly Linear Linked list Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode * next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();
        
        void InsertFirst(T);
        void InsertLast(T);

        void DeleteFirst();
        void DeleteLast();

        void InsertAtPos(T, int);
        void DeleteAtPos(int);

        void Display();

        int Count();
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Doubly Linked List gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this-> first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first -> prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this-> first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }

    this->iCount++;
} 

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains one node
    {
        delete this->first;
        this->first = NULL;
    }       
    else                                    // LL contains more than one node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

template<class T>
void DoublyLLL<T> :: DeleteLast()
{    
    DoublyLLLnode<T>* temp = NULL;

    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains one node
    {
        delete this->first;
        this->first = NULL;
    }       
    else                                    // LL contains more than one node
    {
        temp = this->first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete (temp -> next);
        temp -> next = NULL;
    }
    this->iCount--;
}

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T>* newn = NULL;
    DoublyLLLnode<T>* temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout<<"invalide Position\n";
        return;
    }
    
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next-> prev = newn;
        temp->next= newn;
        newn -> prev = temp;

        this->iCount++;
    }
}

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T>* temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"invalide Position\n";
        return;
    }
    
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
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
        temp -> next = temp -> next -> next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;
    temp = this->first;

    cout<<"\nNULL<==>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<==>";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                                  Stack Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;

    public:
        Stack();

        void Push(T);         
        T Pop();            
        T Peep();
        void Display();
        int Count();
};
/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
Stack<T> :: Stack()
{
    cout<<"Stack is Created...\n";
    this->first = NULL;
    this->iCount = 0;
}

/*------------------------------------------------------------------------------------------------------------------------------*/
template <class T>
void Stack<T> :: Push(T no)
{
    Stacknode<T> * newn = NULL;
    newn = new Stacknode<T>(no);

    newn -> next= this->first;
    this->first = newn;

    this->iCount++;
}

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
T Stack<T>:: Pop()
{
    T Value = 0;
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
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
T Stack<T> :: Peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp -> next;
    }
}

/*------------------------------------------------------------------------------------------------------------------------------*/

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                        Queue Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////End Of Library/////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    cout<<"-----------------------------------------------------------------------------------------------------\n";
    
    int iRet = 0;

    SinglyLLL<int> * obj = new SinglyLLL<int>();

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->DeleteFirst();

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->InsertAtPos(105, 4);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    /*---------------------------------------------------------------------------------------------------------*/

    cout<<"-----------------------------------------------------------------------------------------------------\n";

    DoublyLLL<char> * dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('c');

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$', 4);

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";
    cout<<"-----------------------------------------------------------------------------------------------------\n";

    Stack<char>* sobj = new Stack<char>();

    sobj->Push('A');
    sobj->Push('B');
    sobj->Push('C');
    sobj->Push('D');

    sobj->Display();
    cout<<"Numbre of Elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"Return Value of peep is : "<<sobj->Peep()<<"\n";

    sobj->Display();
    cout<<"Numbre of Elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"Poped ELement is : "<<sobj->Pop()<<"\n";

    sobj->Display();
    cout<<"Numbre of Elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"Poped ELement is : "<<sobj->Pop()<<"\n";

    sobj->Display();
    cout<<"Numbre of Elements in stack are: "<<sobj->Count()<<"\n";

    sobj->Push('Z');

    sobj->Display();
    cout<<"Numbre of Elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"-----------------------------------------------------------------------------------------------------\n";

    Queue<double>* qobj = new Queue<double>();

    qobj->EnQueue(11.113434);
    qobj->EnQueue(21.2121);
    qobj->EnQueue(51.12321);
    qobj->EnQueue(101.123112);

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    cout<<"Removed ELement is : "<<qobj->DeQueue()<<"\n";

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    cout<<"Removed ELement is : "<<qobj->DeQueue()<<"\n";

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    qobj->EnQueue(121.123123);

    qobj->Display();
    cout<<"Number of Elements in Queue are: "<<qobj->Count()<<"\n";

    delete qobj;
    delete obj;
    delete sobj;
    delete dobj;


    return 0;
}