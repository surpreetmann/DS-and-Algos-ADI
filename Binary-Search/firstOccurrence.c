/*
Given a sorted list of integers, find the position of first occurrence of a given number K in this list in O(log n) time.
*/
#include <stdio.h>
/* Include other headers as needed */
int main()
{
	int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,k,r,l,i,mid;
    scanf("%d",&n);
    scanf("%d",&k);
    int a[n];
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    r=n-1;
    l=0;
    i=0;
    while(l<r)
    {
      mid=(l+r)/2;
      if(a[mid]>k)
      {
        r=mid-1;
      }
      else if(a[mid]<k)
      {
        l=mid+1;
      }
      else
      {
      //  i=-1;
        r=mid;
      }
    }
    if(a[l]==k)
      printf("%d\n",l);
    else
      printf("-1\n");
  }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}