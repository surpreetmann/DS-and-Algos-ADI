import java.util.*;
class MinStack{
    Stack<Integer> st;
    Integer min=Integer.MAX_VALUE;
    MinStack()
    {
        st=new Stack<Integer>();
    }
    void displayMin()
    {
        if(!st.isEmpty())
       {
            System.out.println("The minimum element is");
            System.out.println(min);
       }    
    }
    void pop()
    {
        if(st.isEmpty())
           System.out.println("Stack is empty");
        else
        {
            Integer ele=st.pop();
            if(ele<min)
                min=2*min-ele;    
        }
        System.out.println(min);   
    }
    void push(Integer ele)
    {
        if(st.isEmpty())
        {
            st.push(ele);
            min=ele;
        }
        else{
            if(ele<min)
            {
                
                st.push(2*ele-min);
                min=ele;
            }
        }
    }
}

public class MinElement
{
    public static void main(String[] args) {
        MinStack s=new MinStack(); 
        s.push(4);
        s.push(3);
        s.push(1);
        s.push(9);
        s.push(19);

        s.displayMin();
        s.pop();

    }
}