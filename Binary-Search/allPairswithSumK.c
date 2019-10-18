/*
Given a sorted list of integers, find all distinct pair of integers in the list of N integers with sum equal to a given number K with O (n log n ) or O(n) time complexity.

Complete the function below which takes the array and K as parameters and return the number of pairs if any and 0 otherwise.
*/
int getPairsCount(int a[], int n, int sum)
{
  int i=0,j=n-1,c=0,i1,j1;
  while(i<j)
  {
    if(a[i]+a[j]==sum)
    {
      for(i1=i+1;a[i1-1]==a[i1]&&i1<j;i1++)
      {}
      for(j1=j-1;a[j1]==a[j1+1]&&j1>i+1;j1--)
      {}
      c=c+(i1-i)*(j-j1);
      i=i1;
      j=j1;
    }
    else if(a[i]+a[j]>sum)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
  return c;
}