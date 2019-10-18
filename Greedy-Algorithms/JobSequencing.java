import java.util.Scanner;

class JobSequencing
{
  public static void swap(int arr[],int i,int j)
  {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
  public static void swap(String arr[],int i,int j)
  {
    String temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }

  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    int jobs=sc.nextInt();
    String h=sc.nextLine();
    String name[]=new String[jobs];
    int p[]=new int[jobs];
    int dead[]=new int[jobs];
    int max=0;
    for(int i=0;i<jobs;i++)
    {
      name[i]=sc.nextLine();
    }
    for(int i=0;i<jobs;i++)
    {
      p[i]=sc.nextInt();
    }
      for(int i=0;i<jobs;i++)
      {
      dead[i]=sc.nextInt();
      if(dead[i]>max)
      max=dead[i];
    }

    for(int i=0;i<jobs;i++)
    {
      for(int j=0;j<jobs-1;j++)
      {
        if(p[j]<p[j+1])
        {
      swap(name,j,j+1);
      swap(p,j,j+1);
      swap(dead,j,j+1);
    }
    }

    }
   
    String arr[]=new String[max];
    for(int k=0;k<max;k++)
    arr[k]="$$";
    for(int i=0;i<jobs;i++)
    {
      for(int j=dead[i]-1;j>=0;j--)
      {
         String f="$$";
        if(arr[j].equals(f))
        {
        arr[j]=name[i];
        break;
      }
      }
    }
    for(int i=0;i<max;i++)
    {
      System.out.println(arr[i]);
    }


  }
}