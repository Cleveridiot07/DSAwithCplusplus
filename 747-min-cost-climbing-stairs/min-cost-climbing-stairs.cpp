class Solution {
    int helper(vector<int> &cost,int index,vector<int> &dp){
        if(index >= cost.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int way1 = helper(cost,index+2,dp);
        int way2 = helper(cost,index+1,dp);

        return dp[index] = cost[index] + min(way1,way2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(helper(cost, 0,dp), helper(cost,1,dp));
    }
};