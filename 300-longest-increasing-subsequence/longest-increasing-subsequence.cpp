class Solution {
    int helper(vector<int> &nums,int i,int prev,vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        // Not Take
        int case1 = helper(nums,i+1,prev,dp);

        // Take
        int case2 = 0;
        if( prev == -1  || nums[i] > nums[prev] ){ 
            case2 = 1 + helper(nums,i+1,i,dp);
        }

        return dp[i][prev+1] = max(case1,case2);

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1,dp);
    }
};