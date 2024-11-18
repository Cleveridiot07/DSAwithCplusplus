#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Memoization
class Solution {
    int robHelper(int idx, int start, int end, vector<int>& nums, vector<int>& dp) {
        if (idx < start) return 0;  // Base case: No houses left to rob
        if (dp[idx] != -1) return dp[idx];  // Return cached result

        // Either rob this house and skip the previous one, or skip this house
        int robCurrent = nums[idx] + robHelper(idx - 2, start, end, nums, dp);
        int skipCurrent = robHelper(idx - 1, start, end, nums, dp);

        return dp[idx] = max(robCurrent, skipCurrent);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Case 1: Rob houses from 0 to n-2
        vector<int> dp1(n, -1);
        int case1 = robHelper(n - 2, 0, n - 2, nums, dp1);

        // Case 2: Rob houses from 1 to n-1
        vector<int> dp2(n, -1);
        int case2 = robHelper(n - 1, 1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};

// Tabulation

class Solution2 {
    int maxR(int n, int start, vector<int>& nums,vector<int> &dp) {

        dp[start] = nums[start];
        if (n == start) return dp[start];
        dp[start+1] = max(nums[start+0], nums[start+1]);

        for (int i = start+2; i <= n; i++) {
            int take = nums[i] + dp[i - 2];
            int nontake = dp[i - 1];
            dp[i] = max(take, nontake);
        }

        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
       
        int n = nums.size();
         if(n<=2) return *max_element(nums.begin(),nums.end());
        vector<int> dp(n,-1);
        int opt1 = maxR(n-1,1,nums,dp);
        vector<int> dp2(n,-1);
        int opt2 = maxR(n-2,0,nums,dp2);
        return max(opt1,opt2);
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
