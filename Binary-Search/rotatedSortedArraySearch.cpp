/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*This code works for the array with duplicates too.*/
int Solution::search(const vector<int> &A, int B) {
      
    int i = 0, j = A.size() - 1;
    while(i <= j)
    {
        int mid = (i + j) / 2;
        
        if(A[mid] == B)
            return mid;
            
        if(A[i] <= A[mid]){
            
            if(B > A[mid])      
                i = mid + 1;
            
            else{ 
                if(B >= A[i])
                    j = mid - 1;
                else       
                    i =  mid + 1;
            }
            
        }
        
        else if(A[j] > A[mid]){
            
            if(B < A[mid])     
                j = mid - 1;
            
            else{  
                if(B <= A[j])
                    i = mid + 1;
                else      
                    j =  mid - 1;
            }
            
        }
    }
    
    return -1;
    
}
