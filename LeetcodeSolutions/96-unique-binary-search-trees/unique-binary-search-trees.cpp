class Solution {
    int numberOfWays(int n,vector<int> &dp){
        if(n == 0 || n == 1) return 1;  

        if(dp[n] != -1) return dp[n];
        int number = 0;
        for(int i = 1; i <= n; i++){
            int left = numberOfWays(i - 1,dp);  
            int right = numberOfWays(n - i,dp); 

            number += (left * right); 
        }

        return dp[n] = number;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return numberOfWays(n,dp);
    }
};