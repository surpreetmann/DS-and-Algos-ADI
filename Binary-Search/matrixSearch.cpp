/*
Write an efficient algorithm that searches for a value in an m x n matrix.
*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    // for(int i=0;i<A.size();i++)
    // {
    //     int x=binary_search(A[i].begin(),A[i].end(),B);
    //     if(x)
    //         return 1;
    // }
    // return 0;
    
    int n=A.size();
    if(n==0) 
        return 0;
    int m=A[0].size();
    if(m==0) 
        return 0;

    int low = 0;
    int high = m*n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(A[mid/m][mid%m]==B)
            return 1;
        if(A[mid/m][mid%m]<B)
            low=mid+1;
        else 
            high=mid-1;
}
return 0;
}
