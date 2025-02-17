class Solution {
    int helper(vector<int> &nums,int index,int prevIndex,vector<vector<int>> &dp){
        if(index >= nums.size()) return 0;
        if(dp[index][prevIndex + 1] != -1) return dp[index][prevIndex + 1 ];
        // Not Take
        int way1 = helper(nums,index+1,prevIndex,dp);

        int way2 = 0;
        // Take
        if(prevIndex < index-1 || prevIndex == -1){
            way2 = nums[index] + helper(nums,index+1,index,dp);
        }

        return dp[index][prevIndex+1] =  max(way1,way2);
    }
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>( nums.size(),-1));
        return helper(nums,0,-1,dp);
    }
};