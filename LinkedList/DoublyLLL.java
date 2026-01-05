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
    {
        node temp = null;
        temp = first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |<==>");
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
        newn = new node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node temp = null;
        node newn = null;
        newn = new node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }

    public void DeleteFirst()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;
            first = first.next;

            first.prev = null;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;
        
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;
            
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void InsertAtPos(int no, int pos)
    {}

    public void DeleteAtPos(int pos)
    {}
}

class DoublyLLL
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