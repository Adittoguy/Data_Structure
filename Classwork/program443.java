class node              // self referential class
{
    public int data;
    public node next;

    // IMP
    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
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
    {
        node temp = null;
        temp = this.first;

        while(temp != null)
        {
            System.out.print("| "+ temp.data +" |-->");
            temp = temp.next;
        }   
        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        // changed code
        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node temp = null;

        node newn = null;
        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.iCount++;
    }

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void InsertAtPos(int no, int pos)
    {}

    public void DeleteAtPos(int pos)
    {}
}

class program443
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

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Total nodes in linked list are: "+iRet);

        //IMP for memory deallocation
        obj = null;
        System.gc();
    }
}