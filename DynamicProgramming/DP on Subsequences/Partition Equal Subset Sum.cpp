#include <iostream>
#include <vector>
using namespace std;

// Memoization

class Solution {
    bool helper(vector<int> &nums, int target, int index, vector<vector<int>> &dp) {
        // Base case: If the target is 0, we can partition successfully
        if (target == 0) return true;

        // If we are at the first index, check if the current element equals the target
        if (index == 0) return (target == nums[0]);

        // Check if the result is already computed
        if (dp[index][target] != -1) return dp[index][target];

        // Not Take: Skip the current element
        bool notTake = helper(nums, target, index - 1, dp);

        // Take: Include the current element in the subset, if it does not exceed the target
        bool take = false;
        if (target >= nums[index]) take = helper(nums, target - nums[index], index - 1, dp);

        // Store the result in dp and return
        return dp[index][target] = notTake || take;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // Calculate the total sum of the array
        for (int a : nums) sum += a;

        // If the sum is odd, it's impossible to partition into two equal subsets
        if (sum % 2 != 0) return false;

        // Initialize a DP table for memoization
        vector<vector<int>> dp(nums.size(), vector<int>((sum / 2) + 1, -1));

        // Check if we can find a subset with sum = sum/2
        return helper(nums, sum / 2, nums.size() - 1, dp);
    }
};

/*
 * Time Complexity: O(n * target)
 * - The helper function processes each index (n elements) and each target from 0 to sum/2.
 *
 * Space Complexity: O(n * target)
 * - The DP table requires O(n * target) space for memoization.
 */

// Tabulation

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        // Calculate the total sum of the array
        for (int a : nums) sum += a;

        // If the sum is odd, it's impossible to partition into two equal subsets
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // Initialize a DP table
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case: For any element, we can achieve a sum of 0 by not taking any elements
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: If the first element is less than or equal to the target, mark it as achievable
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                // Not take the current element
                bool notTake = dp[i - 1][j];

                // Take the current element if its value does not exceed the target
                bool take = false;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = notTake || take;
            }
        }

        // The answer is whether we can achieve the target sum using all elements
        return dp[n - 1][target];
    }
};

/*
 * Time Complexity: O(n * target)
 * - We iterate over all elements (n) and for each element, we iterate over all target sums from 0 to target.
 *
 * Space Complexity: O(n * target)
 * - A 2D DP table of size n x (target + 1) is used.
 */

int main() {
    Solution sol;

    vector<int> nums1 = {1, 5, 11, 5}; // Expected output: true
    vector<int> nums2 = {1, 2, 3, 5}; // Expected output: false

    cout << "Can partition {1, 5, 11, 5}: " << (sol.canPartition(nums1) ? "True" : "False") << endl;
    cout << "Can partition {1, 2, 3, 5}: " << (sol.canPartition(nums2) ? "True" : "False") << endl;

    return 0;
}
