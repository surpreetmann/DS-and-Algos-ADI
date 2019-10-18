import java.util.Scanner;
public class ZAlgo
{
    public static void main(String a[])
    {
        Scanner sc=new Scanner(System.in);
        String bstr=sc.nextLine();
        String sstr=sc.next();
        int j=0,c=0;
        int arr[]=new int[bstr.length()];
        for(int i=0;i<bstr.length();i++)
        {
            if(j==sstr.length())
                j=0;
            if(sstr.charAt(j)==bstr.charAt(i))
            {
               
                c++;
                if(c==sstr.length())
                {
                    arr[i-j]=1;
                    c=0;
                }
                 j++;
                
            }
            else
            {
                c=0;
                j=0;
            }
        }
        for(int i=0;i<bstr.length();i++)
         if(arr[i]==1)
                System.out.println(i);
    }
}