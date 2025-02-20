class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Step 1: Compute the points array
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> points(maxNum + 1, 0);
        
        for (int num : nums) {
            points[num] += num;
        }

        // Step 2: Apply House Robber DP
        vector<int> dp(maxNum + 1, 0);
        dp[0] = 0;
        dp[1] = points[1];

        for (int i = 2; i <= maxNum; i++) {
            dp[i] = max(dp[i - 1], points[i] + dp[i - 2]);
        }

        return dp[maxNum];
    }
};
