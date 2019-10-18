class Node {
    int data;
    Node next;
    Node(int d)
    {
        data=d;
        next=null;
    }
}
public class RemoveLoop {
  static void insert(Node head,int data)
  {
    if(head==null)
    {
        head=new Node(data);
        return;
    }
    Node temp=head;
    while(temp.next!=null)
    {
        temp=temp.next;
    }
    temp.next = new Node(data);
  }

  static int findAndCountLoop(Node head) {
    Node slow = head;
    Node fast = head;
    int temp = 0;
    while(slow!=null&&fast!=null&&fast.next!=null)
    {
      slow=slow.next;
      fast=fast.next.next;
      if(slow==fast)
      {
        temp=1;
        break;
      }
    }
    if(temp == 0)
      return 0;
    else 
    {
      int count = 0;
      slow = slow.next;
      while(slow!=fast)
      {
        slow=slow.next;
        count++;
      }
      return count+1;
    }
  }
  
  static int removeLoop(Node head) 
  {
    Node  slow = head;
    Node  fast = head;
    int temp=0;
    while (slow != null && fast != null && fast.next != null) 
    {
        slow = slow.next;
        fast = fast.next.next;
        if (fast == slow)
        {	
            temp = 1;
            break;
        }
    }

    if(temp != 1)
    return 0; 
    
    Node temp1 = slow;
    Node temp2 = slow;
    int count = 1, i;
    while (temp1.next != temp2) {
        temp1 = temp1.next;
        count++;
    }

    temp1 = head;

    temp2 = head;
    for (i = 0; i < count; i++) {
        temp2 = temp2.next;
    }

    while (temp2 != temp1) {
        temp1 = temp1.next;
        temp2 = temp2.next;
    }

    while (temp2.next != temp1) {
        temp2 = temp2.next;
    }

    temp2.next=null;

    return 1;
  }

  static void printList(Node head)
  {
    if(head==null)
      return;

    System.out.println(head.data);

    printList(head.next);
  }

  public static void main(String args[])
  {
    Node head=new Node(1);
    insert(head,6);
    insert(head,5);
    insert(head,6);
    insert(head,1);
    insert(head,14);
    insert(head,85);
    insert(head,78);
    insert(head,9);
    insert(head,21);

    head.next.next.next.next.next = head.next; 

    int bool = removeLoop(head);
    if(bool!=0)
        System.out.println("Loop Found and removed.");
    else
        System.out.println("Loop Not Found");


  }
}