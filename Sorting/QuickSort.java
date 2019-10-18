import java.util.Scanner;
public class QuickSort
{
    
    public static int divide(int arr[],int start,int end)
    {
        int f = start-1, temp, element = arr[end];

        while(start<=end-1)
        {
            if(arr[start]<=element)
            {
                f++;
                temp=arr[f];
                arr[f]=arr[start];
                arr[start]=temp;
            }
            start++;
        }

        temp=arr[f+1];
        arr[f+1]=arr[end];
        arr[end]=temp;

        return (f+1);
    }
    public static void quicksort(int arr[],int start,int end)
    {
        int temp;
        if(start < end)
        {
            temp=divide(arr,start,end);
            quicksort(arr,start,temp-1);
            quicksort(arr,temp+1,end);
        }
    }
    public static void main(String a[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[n];
        
        for(int i = 0 ; i < n ; i++)
            arr[i]=sc.nextInt();
        
        quicksort(arr,0,n-1);
        
        for(int i = 0; i < n ; i++)
            System.out.print(arr[i]+" ");
    }
}