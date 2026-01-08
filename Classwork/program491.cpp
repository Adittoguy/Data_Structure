#include<iostream>
using namespace std;

#pragma pack(1)
class Stacknode
{
    public:
        int data;
        Stacknode * next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Stack
{
    private:
        Stacknode * first;
        int iCount;

    public:
        Stack();

        void Push(int);         // Insertfirst
        int Pop();              // DeleteFirst
        int Peep();
        void Display();
        int Count();
};

Stack :: Stack()
{
    
}

void Stack :: Push(int no)
{
    
}

int Stack :: Pop()
{
    return 0;
}

int Stack :: Peep()
{
    return 0;
}

void Stack :: Display()
{

}

int Stack :: Count()
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
    
    return 0;
}