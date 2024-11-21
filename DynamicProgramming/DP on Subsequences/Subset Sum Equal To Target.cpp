#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool helper(vector<int>& arr, int index, int target, vector<vector<int>>& dp) {
        if (target == 0) return true; // Subset with sum 0 is always possible (empty set).
        if (index >= arr.size() || target < 0) return false; // Out of bounds or invalid subset.

        if (dp[index][target] != -1) return dp[index][target]; // Return cached result.

        // Two choices: skip the current element or include it.
        return dp[index][target] = helper(arr, index + 1, target, dp) || 
                                   helper(arr, index + 1, target - arr[index], dp);
    }

public:
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1)); // Initialize DP array.
        return helper(arr, 0, target, dp);
    }
};

/*
 * Time Complexity: O(n * target)
 * - States to compute are n (size of array) * target (sum value).
 * - Each state is computed once due to memoization.
 * 
 * Space Complexity: O(n * target) + O(N)
 * - Space for the DP array: O(n * target).
 * - Space for the recursion stack: O(n) (maximum depth of recursion).
 */


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];
}

/*
 * Time Complexity: O(n * target)
 * - States to compute are n (size of array) * target (sum value).
 * - Each state is computed once due to memoization.
 * 
 * Space Complexity: O(n * target) 
 * - Space for the DP array: O(n * target).
 * - Space for the recursion stack: O(n) (maximum depth of recursion).
 */



bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a vector 'prev' to store the previous row of the DP table
    vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }

        // Update 'prev' with the current row 'cur' for the next iteration
        prev = cur;
    }

    // The final result is stored in prev[k]
    return prev[k];
}

/*
 * Time Complexity: O(n * k)
 * - We iterate through the array (n elements).
 * - For each element, we iterate through all target sums from 1 to k.
 *
 * Space Complexity: O(k)
 * - Instead of storing the entire DP table (O(n * k)), we use two rows: 'prev' and 'cur', each of size O(k).
 */

int main() {
    Solution solution;

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    if (solution.isSubsetSum(arr, target)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "Subset with the given sum does not exist." << endl;
    }

    return 0;
}
