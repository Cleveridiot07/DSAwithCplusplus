class Solution {
    int helper(vector<int> &coins, int i,int amount,vector<vector<int>> &dp){
        if(i < 0){
            return amount == 0 ? 1 : 0;
        }
        if(amount == 0) return 1;
        if(amount < 0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int opt1 = helper(coins,i-1,amount,dp);
        int opt2 = 0;
        if(coins[i] <= amount) opt2 = helper(coins,i,amount-coins[i],dp);

        return  dp[i][amount] = opt1 + opt2;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return helper(coins,n,amount,dp);
    }
};