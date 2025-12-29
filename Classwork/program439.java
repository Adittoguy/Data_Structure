class node              // self referential class
{
    public int data;
    public node next;
}

class SinglyLL
{
    public node first;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Object of Singlyll gets created.");
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {}

    public int Count()
    {
        return this.iCount;
    }

    public void InsertFirst(int no)
    {}

    public void InsertLast(int no)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void InsertAtPos(int no, int pos)
    {}

    public void DeleteAtPos(int pos)
    {}
}

class program439
{
    public static void main(String A[])
    {
        int iRet = 0;

        SinglyLL obj = null;
        obj = new SinglyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);
    }
}