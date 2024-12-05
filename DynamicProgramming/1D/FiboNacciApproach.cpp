#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // Recursion method
    int fibR(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fibR(n-1) + fibR(n-2);
    }
    // Time Complexity = O(2^n)
    // Space Complexity = O(n) for stack space


    // Memoization method
    int helperM(int n,vector<int> &dp){
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helperM(n-1,dp)+helperM(n-2,dp);
    }
    int fibM(int n) {
        vector<int> dp(n+1,-1);
        return helperM(n,dp);
    }
    // Time Complexity  = O(n)
    // Space Complexity = O(n) for dp array and O(n) for Recursion Stack


    // Tabulation method
    int fib(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        if(n>0) dp [1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    // Time Complexity  = O(n)
    // Space Complexity = O(n) for dp array

    // swap method
    int fibS(int n) {
        int a = 0;
        int b = 1;
        if(n == 0) return 0;
        int c;
        while(n-2 >= 0){
            c = a+b;
            a = b;
            b = c;
            n--;
        }
        return c;
    }
    // Time Complexity  = O(n)
    // Space Complexity = O(1) for additional variables a, b and c.
};