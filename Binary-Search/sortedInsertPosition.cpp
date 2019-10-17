/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/

int Solution::searchInsert(vector<int> &arr, int B) {
   
    int mid=-1,ans=-1;
    int l=0,r=arr.size()-1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(arr[mid]==B)
        {
            return mid;
        }
        else if(arr[mid]>B)
        {
            r=mid-1;
            if(arr[r]<B)
                return r;
        }
        else
        {
            l=mid+1;
            if(arr[l]>B)
            {
                return mid;
            }
        }
        
    }
    
}
