#include <iostream>
using namespace std;

void min_heapify(int arr[],int i,int n)
{
    int l=2*i;
    int r=2*i+1;
    int max = i;
    if(l<=n && arr[l]<=arr[i])
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if(r<=n && arr[r]<=arr[max])
    {
        max = r;
    }
    if(max!=i)
    {
        swap(arr[i],arr[max]);
        min_heapify(arr,max,n);   
    }
}

void min_maitainheap(int arr[],int i)
{
    if(i/2==0)
    return;

    if(arr[i/2]>=arr[i])
    {
        swap(arr[i/2],arr[i]);
        min_maitainheap(arr,i/2);
    }
}

void min_insertheapify(int arr[],int &n,int v)
{
    arr[++n]=v;
    min_maitainheap(arr,n);
}

void min_deleteheapify(int arr[],int &n)
{
    arr[1]=arr[n--];
    min_heapify(arr,1,n);
}



int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k;
	    cin>>n;
	    int arr[k];
	    int v;
	    int heap_size=0;
	    for(int i=1;i<=n;i++)
	    {
	        cin>>v;
	        if(heap_size<k)
	        {
                min_insertheapify(arr,heap_size,v);
	        }
            else if(v>arr[1])
            {
                min_deleteheapify(arr,heap_size);
                min_insertheapify(arr,heap_size,v);
            }
            if(heap_size<k)
            cout<<"-1 ";
            else
            cout<<arr[1]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}