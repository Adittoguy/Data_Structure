// SINGLY CIRCULAR

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

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created.");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = null;
        temp = first;
        do
        {
            System.out.print("| "+temp.data+" |-->");
            temp = temp.next;
        }while(temp != last.next);
        System.out.print("null\n");
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;   
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        last.next = first;
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            temp = first;
            last.next = newn;
            last = newn;
        }
        last.next = first;
        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
        }
        last.next=first;
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;

            while(temp.next != last)
            {
                temp = temp.next;
            }
            last = temp;
        }
        last.next=first;
        iCount--;
    }

    public void InsertAtPos(int no, int pos)
    {
        int iCnt = 0;

        node newn = null;
        node temp = null;

        if((pos > iCount + 1) || (pos < 0))
        {
            System.out.println("Invalid Position");
            return;
        }
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = first;
            newn = new node(no);

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
        last.next=newn;
    }

    public void DeleteAtPos(int pos)
    {
        int iCnt = 0;

        node temp = null;
        
        if((pos > iCount + 1) || (pos < 0))
        {
            System.out.println("Invalid Position");
            return;
        }
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            last.next = first;
            iCount--;
        }
    }
}

class SinglyCLL
{
    public static void main(String A[])
    {
        int iRet = 0;

        SinglyCL obj = null;
        obj = new SinglyCL();

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