#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int helper(vector<int>& arr, int index, int target, vector<vector<int>>& dp) {
        // Base Case
        if (index == 0) {
            int count = 0;
            // Two cases to handle for base condition
            if (target == 0) count++;              // Empty subset
            if (target == arr[index]) count++;     // Single element subset
            return count;
        }

        // Return if the result is already computed
        if (dp[index][target] != -1) return dp[index][target];

        // Not Take (exclude current element)
        int notTake = helper(arr, index - 1, target, dp);

        // Take (include current element if it does not exceed the target)
        int take = 0;
        if (arr[index] <= target) {
            take = helper(arr, index - 1, target - arr[index], dp);
        }

        // Store the result in DP table and return
        return dp[index][target] = take + notTake;
    }

public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        // Initialize DP table with -1 (indicating uncomputed states)
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(arr, n - 1, target, dp);
    }
};

/*
 * Time Complexity:
 * - O(n * target), where n is the size of the array and target is the given target sum.
 * - Each subproblem is computed only once and stored in the DP table.
 *
 * Space Complexity:
 * - O(n * target) for the DP table.
 * - O(n) for the recursion stack (depth of recursion).
 */

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 2, 3};
    int target1 = 4;
    cout << "Count of subsets with sum " << target1 << ": " << sol.perfectSum(arr1, target1) << endl;

    // Test case 2
    vector<int> arr2 = {1, 2, 2, 3};
    int target2 = 5;
    cout << "Count of subsets with sum " << target2 << ": " << sol.perfectSum(arr2, target2) << endl;

    // Test case 3
    vector<int> arr3 = {0, 0, 1};
    int target3 = 1;
    cout << "Count of subsets with sum " << target3 << ": " << sol.perfectSum(arr3, target3) << endl;

    return 0;
}
