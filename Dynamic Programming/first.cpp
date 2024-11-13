#include<bits/stdc++.h>
using namespace std;

#define int long long int

//we use DP when we have overlapping subproblems
//Top Down Approach -> recursion + memoization 
//Bottom Up Approach -> tabulation

//top down approach
int fib(int n, vector<int> &dp){
    // base case
    if(n==0 || n==1) return n;

    //check if solution already exist
    if(dp[n] != -1) return dp[n];

    //else find the solution, first save it, then return it
   dp[n] = fib(n-1, dp) + fib(n-2, dp);
   return dp[n];
}

//bottom up approach
int fib2(int n){
    //make a dp table
    vector<int> dp(n+1);
    
    //now write down base cases of the recursion
    dp[0] = 0;
    dp[1] = 1;

    //now fill the remaining dp array
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    //now return the answer
    return dp[n];
}

//space optimization method
int fib3(int n){
    if(n==0) return 0;
    int prev1 = 0;
    int prev2 = 1;
    for(int i=2;i<=n;i++){
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

signed main(){
    int n=9999;
    // vector<int> dp(n+1, -1);
    // cout<<fib(n, dp)<<endl;
    cout<<fib3(n)<<endl;
}