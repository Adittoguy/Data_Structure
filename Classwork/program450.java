// Doubly LINEAR

class node              // self referential class
{
    public int data;
    public node next;
    public node prev;

    // IMP
    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    private node first;
    private int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created.");
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

class program450
{
    public static void main(String A[])
    {
        int iRet = 0;

        DoublyLL obj = null;
        obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);

        obj.InsertAtPos(105, 4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);

        obj.DeleteAtPos(4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);

        //IMP for memory deallocation
        obj = null;
        System.gc();
    }
}