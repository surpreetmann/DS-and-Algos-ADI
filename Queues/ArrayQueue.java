package surpreet_ds;

public class ArrayQueue<E> implements Queue<E>
{
  // instance variables
  /** Default array capacity. */
  public static final int CAPACITY = 1000;      // default array capacity

  /** Generic array used for storage of queue elements. */
  private E[] data;                             // generic array used for storage

  /** Index of the top element of the queue in the array. */
  private int f = -1;                            // index of the front element

  /** Index of the bottom element of the queue in the array. */
  private int r=-1;                             // index of the rear element

  /** Current number of elements in the queue. */
  private int size = 0;                           // current number of elements

  // constructors
  /** Constructs an empty queue using the default array capacity. */
  public ArrayQueue()
  {
    data=(E[])new Object[CAPACITY];
  }         // constructs queue with default capacity

  /**
   * Constructs and empty queue with the given array capacity.
   * @param capacity length of the underlying array
   */
  @SuppressWarnings({"unchecked"})
  public ArrayQueue(int capacity)
  {
    data=(E[])new Object[capacity];
  }

  // methods
  /**
   * Returns the number of elements in the queue.
   * @return number of elements in the queue
   */
  @Override
  public int size()
  {
    return size;
  }

  /** Tests whether the queue is empty. */
  @Override
  public boolean isEmpty()
  {
    return size==0;
  }

  /**
   * Inserts an element at the rear of the queue.
   * This method runs in O(1) time.
   * @param e   new element to be inserted
   * @throws IllegalStateException if the array storing the elements is full
   */
  @Override
  public void enqueue(E e) throws IllegalStateException
  {
    if(size==CAPACITY)  //Queue is full.
      return;
    if(f==-1 && r==-1)
    {
      f++;
      r++;
    }
    else
      r++;
    data[r]=e;
    size++;
  }

  /**
   * Returns, but does not remove, the first element of the queue.
   * @return the first element of the queue (or null if empty)
   */
  @Override
  public E first()
  {
    if(isEmpty())
      return null;
    return data[f];
  }

  /**
   * Removes and returns the first element of the queue.
   * @return element removed (or null if empty)
   */
  @Override
  public E dequeue()
  {
    if(isEmpty())
      return null;
    /*if(front>rear)
        return null;*/
    E ele=data[f];
    f++;
    size--;
    return ele;
  }

  /**
   * Returns a string representation of the queue as a list of elements.
   * This method runs in O(n) time, where n is the size of the queue.
   * @return textual representation of the queue.
   */
  public String toString()
  {
      StringBuilder sb=new StringBuilder("(");
      int i;
      for(i=f;i<r;i++)
      {
        sb.append(data[i]);
        sb.append(", ");
      }
      sb.append(data[i]);
      sb.append(")");
      return sb.toString();
  }
  /** Demonstrates sample usage of a queue. */
/*  public static void main(String[] args) {
  Queue<Integer> Q = new ArrayQueue<>();  // contents: ()
  Q.enqueue(5);                              // contents: (5)
  Q.enqueue(3);                              // contents: (5, 3)
  System.out.println(Q.size());           // contents: (5, 3)     outputs 2
  System.out.println(Q.dequeue());            // contents: (5)        outputs 5
  System.out.println(Q.isEmpty());        // contents: (3)        outputs false
  System.out.println(Q.dequeue());            // contents: ()         outputs 3
  System.out.println(Q.isEmpty());        // contents: ()         outputs true
  System.out.println(Q.dequeue());            // contents: ()         outputs null
  Q.enqueue(7);                              // contents: (7)
  Q.enqueue(9);                              // contents: (7, 9)
  System.out.println(Q.first());            // contents: (7, 9)     outputs 7
  Q.enqueue(4);                              // contents: (7, 9, 4)
  System.out.println(Q.size());           // contents: (7, 9, 4)  outputs 3
  System.out.println(Q.dequeue());            // contents: (9, 4)     outputs 7
  Q.enqueue(6);                              // contents: (9, 4, 6)
  Q.enqueue(8);                              // contents: (9, 4, 6, 8)
  System.out.println(Q.dequeue());            // contents: (4, 6, 8)  outputs 9
  System.out.println(Q.toString());*/
}
