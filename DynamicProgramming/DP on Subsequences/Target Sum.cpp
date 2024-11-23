class Solution {
    int helper(vector<int>& nums, int index, int target, vector<vector<int>>& dp, int offset) {
        if (abs(target) > offset) {
            return 0;
        }

        if (index < 0) {
            return (target == 0) ? 1 : 0; 
        }

        if (dp[index][target + offset] != -1) {
            return dp[index][target + offset];
        }

        int add = helper(nums, index - 1, target - nums[index], dp, offset);
        int subtract = helper(nums, index - 1, target + nums[index], dp, offset);

        return dp[index][target + offset] = add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum) {
            return 0;
        }

        int offset = sum; 
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
        return helper(nums, nums.size() - 1, target, dp, offset);
    }
};