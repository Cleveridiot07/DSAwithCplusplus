class Solution {
    int numberOfWays(int n,vector<int> &dp){
        if(n == 0 || n == 1) return 1;  
        if(dp[n] != -1) return dp[n];
        int number = 0;
        for(int i = 1; i <= n; i++){
            number += numberOfWays(i - 1,dp) * numberOfWays(n - i,dp); 
        }

        return dp[n] = number;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return numberOfWays(n,dp);
    }
};