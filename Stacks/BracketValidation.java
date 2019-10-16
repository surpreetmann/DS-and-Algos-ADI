import java.util.*;
public class BracketValidation{
    static boolean ValidParentheses(String s) {
        char st[]=new char[s.length()];
        int top=-1;
        int i=0,num=0;
        while(i<s.length())
        {
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='[')
            {
                st[++top]=s.charAt(i);
            }
            else if(s.charAt(i)==')' || s.charAt(i)=='}' || s.charAt(i)==']')
            {
                if(top!=-1)
                if((st[top]=='(' && s.charAt(i)==')') || (st[top]=='{' && s.charAt(i)=='}') ||                    (st[top]=='[' && s.charAt(i)==']') )
            {
                top--;
            }
        }
            i++;
            
        }
        if(top<0)
            return true;
        else
            return false;
    }


    public static void main(String[] args)
    {
        String str;
        Scanner sc=new Scanner(System.in);
        str=sc.nextLine();
        boolean val=ValidParentheses(str);
        if(val==false)
            System.out.println("String is not balanced");
        else
            System.out.println("String is balanced");
    }
}    