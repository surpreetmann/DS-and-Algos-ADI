#include<stdio.h>
#define max 12

int st[max],n,top[5],tos[5],buttom[5],ch,sn,ele,i,size,item;
void main()
{
printf("Enter The Number of Stack \n");
scanf("%d",&n);
size=max/n;
buttom[0]=-1;

for(i=1;i<n;i++)
buttom[i]=buttom[i-1]+size;

for(i=0;i<n;i++)
tos[i]=buttom[i];

for(i=0;i<n;i++)
top[i]=buttom[i]+size;
do{
printf("\n 1-PUSH \n 2-POP \n 3-Display \n 4-Exit \n\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter The Stack Number to PUSH \n");
	scanf("%d",&sn);
	printf("Enter The element \n");
	scanf("%d",&ele);
	push(sn,ele);
	break;

case 2 :printf("Enter The Stack Number POP \n");
	scanf("%d",&sn);
	pop (sn);
	break;

case 3: printf("Enter The Stack Number To Display \n");
	scanf("%d",&sn);
	disp(sn);
	break;
}
}while(ch<=3);
}

void push(int sn,int ele)
{
if (tos[sn]==top[sn])
printf("Stact %d is Overflowing \n",sn);

else
st[++tos[sn]]=ele;
}

void pop(int sn)
{
if (tos[sn]==buttom[sn])
printf("The Stack %d is in Underflow Condition \n",sn);

else
item=tos[sn];
tos[sn]--;
printf("Element Popped is ");
}

void disp(int sn)
{
if (tos[sn]==buttom[sn])
printf("Nothing to Show :-( stack is Empty \n");
else
for (i=tos[sn];i>buttom[sn];i--)
printf("Elements are : %d \t",st[i]);
}