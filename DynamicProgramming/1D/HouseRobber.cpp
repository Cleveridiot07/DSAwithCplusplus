#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Memoization Top-down
class Solution {
    int maxR(int n, vector<int>& nums, vector<int>& dp) {
        if (n < 0) return 0; // Base case: no houses to rob
        if (dp[n] != -1) return dp[n]; // Return memoized result

        // Either rob the current house or skip it
        int rob = nums[n] + maxR(n - 2, nums, dp); // Rob current house
        int skip = maxR(n - 1, nums, dp);          // Skip current house

        return dp[n] = max(rob, skip); // Store and return the best choice
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // No houses to rob
        vector<int> dp(n, -1); // Memoization array
        return maxR(n - 1, nums, dp); // Start from the last house
    }
};



// Tabulation Bottom - UP
class Solution2 {
    int maxR(int n, vector<int>& nums,vector<int> &dp) {

        dp[0] = nums[0];
        if (n == 0) return dp[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i <= n; i++) {
            int take = nums[i] + dp[i - 2];
            int nontake = dp[i - 1];
            dp[i] = max(take, nontake);
        }

        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return maxR(n-1,nums,dp);
    }
};


class Solution {
    int maxR(int n, vector<int>& nums, vector<int>& dp) {
        if (n < 0) return 0; // Base case: no houses to rob
        if (dp[n] != -1) return dp[n]; // Return memoized result

        // Either rob the current house or skip it
        int rob = nums[n] + maxR(n - 2, nums, dp); // Rob current house
        int skip = maxR(n - 1, nums, dp);          // Skip current house

        return dp[n] = max(rob, skip); // Store and return the best choice
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // No houses to rob
        vector<int> dp(n, -1); // Memoization array
        return maxR(n - 1, nums, dp); // Start from the last house
    }
};



int main() {
    Solution solution;
    int n;

    // Input the number of houses
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> nums(n);

    // Input the amount of money in each house
    cout << "Enter the money in each house: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Calculate the maximum money that can be robbed
    int result = solution.rob(nums);

    // Output the result
    cout << "Maximum money that can be robbed: " << result << endl;

    return 0;
}
