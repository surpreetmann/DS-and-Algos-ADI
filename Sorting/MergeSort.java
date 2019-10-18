import java.util.Scanner;
public class MergeSort
{
    public static void merge(int arr[],int left,int middle,int right)
    {
        int temp1 = middle - left + 1;
        int temp2 = right - middle ;
        int L[]=new int[temp1];
        int R[]=new int[temp2];
        
        for(int i=0;i<temp1;i++)
            L[i]=arr[left+i];
        
        for(int i=0;i<temp2;i++)
            R[i]=arr[middle+1+i];
        
        int i=0,j=0,k=left;

        while(i<temp1&&j<temp2)
        {
            if(L[i]<=R[j])
            {
                arr[k]=L[i];
                i++;
            }
            else
            {
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<temp1)
        {
            ar[k]=L[i];
            i++;
            k++;
        }
        while(j<temp2)
        {
            ar[k]=R[j];
            j++;
            k++;
        }
        
    }
    public static void mergeSort(int ar[],int left,int right)
    {
        if(left < right)
        {
            int middle = left + ( right - left ) / 2 ;
            mergeSort ( arr , left , middle ) ;
            mergeSort ( arr , middle + 1 , right );
            merge( arr , left , middle , right ) ;
        }
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        for(int i = 0 ; i < n ; i++)
            arr[i] = sc.nextInt();
        
        mergeSort(arr,0,n-1);
       
        for(int i = 0 ; i < n ; i++)
            System.out.print(arr[i]+" ");
    }
}