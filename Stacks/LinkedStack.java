package surpreet_ds;

public class LinkedStack<E> implements Stack<E>
{
  /** The primary storage for elements of the stack */
  private SinglyLinkedList<E> list = new SinglyLinkedList<>();   // an empty list

  /** Constructs an initially empty stack. */
  public LinkedStack() { }                   // new stack relies on the initially empty list

  /**
   * Returns the number of elements in the stack.
   * @return number of elements in the stack
   */
  @Override
  public int size() {
    return list.size();
  }

  /**
   * Tests whether the stack is empty.
   * @return true if the stack is empty, false otherwise
   */
  @Override
  public boolean isEmpty() {
    return list.isEmpty();
  }

  /**
   * Inserts an element at the top of the stack.
   * @param element   the element to be inserted
   */
  @Override
  public void push(E element) {
    list.addFirst(element);
   }

  /**
   * Returns, but does not remove, the element at the top of the stack.
   * @return top element in the stack (or null if empty)
   */
  @Override
  public E top() {
    return list.first();
  }

  /**
   * Removes and returns the top element from the stack.
   * @return element removed (or null if empty)
   */
  @Override
  public E pop() {
    return list.removeFirst();
  }

  /** Produces a string representation of the contents of the stack.
   *  (ordered from top to bottom)
   *
   * This exists for debugging purposes only.
   *
   * @return textual representation of the stack
   */
  public String toString()
  {
    return list.toString();
  }

  /** Demonstrates sample usage of a stack. */
/*  public static void main(String[] args) {
    Stack<Integer> S = new LinkedStack<>();  // contents: ()
    S.push(5);                              // contents: (5)
    S.push(3);                              // contents: (5, 3)
    System.out.println(S.size());           // contents: (5, 3)     outputs 2
    System.out.println(S.pop());            // contents: (5)        outputs 3
    System.out.println(S.isEmpty());        // contents: (5)        outputs false
    System.out.println(S.pop());            // contents: ()         outputs 5
    System.out.println(S.isEmpty());        // contents: ()         outputs true
    System.out.println(S.pop());            // contents: ()         outputs null
    S.push(7);                              // contents: (7)
    S.push(9);                              // contents: (7, 9)
    System.out.println(S.top());            // contents: (7, 9)     outputs 9
    S.push(4);                              // contents: (7, 9, 4)
    System.out.println(S.size());           // contents: (7, 9, 4)  outputs 3
    System.out.println(S.pop());            // contents: (7, 9)     outputs 4
    S.push(6);                              // contents: (7, 9, 6)
    S.push(8);                              // contents: (7, 9, 6, 8)
    System.out.println(S.pop());            // contents: (7, 9, 6)  outputs 8
    System.out.println(S.toString());
  }*/
}
