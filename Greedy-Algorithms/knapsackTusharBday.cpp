/*
As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.
Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.
Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000
*/


int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

vector<pair<int,int> > v;
    for(int i=0;i<B.size();i++){
        v.push_back(make_pair(B[i],C[i]));
    }
    sort(v.begin(),v.end());
    int dp[B.size()][1000+1];
    for(int j=0;j<B.size();j++){
        dp[j][0]=0;
    }
    for(int j=0;j<=1000;j++){
        dp[0][j]=v[0].second*j;
    }
    for(int i=1;i<B.size();i++){
        for(int it=1;it<=1000;it++){
            if(it>=v[i].first){
                dp[i][it]=min(dp[i-1][it],dp[i][it-v[i].first]+v[i].second);
            }else{
                dp[i][it]=dp[i-1][it];
            }
        }
    }
    int ans=0;
    for(auto iter:A){
        ans+=dp[B.size()-1][iter];
    }
    return ans;
}