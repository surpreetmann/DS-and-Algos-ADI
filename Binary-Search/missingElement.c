#include <stdio.h>

int main()
{
	int t,n,m;
  scanf("%d",&t);
  while(t-->0)
  {
    scanf("%d%d",&n,&m);
    int a[n],b[m];
    int i,j,sum=0,sum1=0
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      sum=sum+a[i];
    }
    for(j=0;j<m;j++)
    {
      scanf("%d",&b[j]);
      sum1=sum1+b[j];
    }
    printf("%d\n",(sum-sum1));
  }
   
    return 0;
}