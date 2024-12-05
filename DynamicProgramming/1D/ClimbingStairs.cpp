#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
// Recursion
    // int climbStairs(int n) {
    //     if(n <= 2) return n;
    //     return climbStairs(n-1) + climbStairs(n-2);
    // }
    
    // Time Complexity = O(2^n)
    // Space Complexity = O(n) for Recursion Stack 

// Memoization
    // int helper(int n, vector<int> &dp){
    //     if(n <= 2) return n;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = helper(n-1,dp) + helper(n-2,dp);
    // }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);
    //     return helper(n,dp);
    // }
    // Time Complexity = O(n) 
    // Space Complexity = O(n) for Recursion Stack + O(n) for dp vector 

// Tabulation
    // int climbStairs(int n) {
    //     vector<int> dp(n+1);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     if(n>=2) dp[2] = 2;
    //     for(int i=3;i<=n;i++){
    //         dp[i] =dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }
    // Time Complexity = O(n) 
    // Space Complexity = O(n) for dp vector 

// swap method
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        if(n <= 2) return n;
        int c;
        while(n-2 > 0){
            c = a+b;
            a = b;
            b = c;
            n--;
        }
        return c;
    }
    // Time Complexity = O(n) 
    // Space Complexity = O(1) for additional variables 
    
};
