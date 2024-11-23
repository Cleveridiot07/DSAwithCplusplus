class Solution {
    int helper(vector<int>& coins, int amount, int index,vector<vector<int>> &dp) {
        if (amount == 0) return 0; 
        if (index < 0 || amount < 0) return INT_MAX; 

        if(dp[index][amount] != -1) return dp[index][amount];

        int notTake = helper(coins, amount, index - 1,dp);

        int take = INT_MAX;
        if (coins[index] <= amount) {
            int res = helper(coins, amount - coins[index], index,dp); 
            if (res != INT_MAX) take = 1 + res; 
        }

        return dp[index][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int result = helper(coins, amount, coins.size() - 1,dp);
        return (result == INT_MAX) ? -1 : result; 
    }
};