#include<bits/stdc++.h>
using namespace std;

int solve(int n, int curr){
        if(curr == n-1) return 1;
        if(curr == n-2) return 2;
        if(curr == n-3) return 3;
        
        return solve(n, curr+1) + solve(n, curr+2);

}

int climbStairs(int n) {
    return solve(n, 0);
}

int main(){
    cout<<climbStairs(6);
}