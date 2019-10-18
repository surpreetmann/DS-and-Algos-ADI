/*
int top = -1;
int front1=-1, rear1=-1;
int front2=-1, rear2=-1;
int q1[SIZE], q2[SIZE];

void enqueue(int q[], int *f, int *r, int item);
int dequeue(int q[], int *f, int *r);

Above two queue and their enqueue and dequeue functions are available, 
So complete the below two methods to implement stack using these functions. */


// Function to add an item to stack.
int push(int item)
{
  int n;
  if(front1!=-1&&rear1!=-1)
  	n = rear1-front1;
  else
    n = -1;
  for(int i = 0 ; i <= n ; i++)
    enqueue(q2,&front2,&rear2,dequeue(q1,&front1,&rear1));
  enqueue(q1,&front1,&rear1,item);
  if(n!=-1)
  	n = rear2-front2;
  for(int i = 0 ; i <= n ; i++)
  {
    enqueue(q1,&front1,&rear1,dequeue(q2,&front2,&rear2));
  }
}

// Function to remove an item from stack.
int pop()
{
  //printf("in pop");
  //printf("%d",dequeue(q1,&front1,&rear1));
  if(front1==-1&&rear1==-1)
    return -1;
  return dequeue(q1,&front1,&rear1);
}