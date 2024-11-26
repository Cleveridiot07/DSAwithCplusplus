#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    // Helper function for the recursive + memoization approach
    int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        // Base case: If we reach the end of string `t`, we found a valid subsequence
        if (j >= t.size()) return 1;
        // Base case: If we reach the end of string `s` without matching all of `t`
        if (i >= s.size()) return 0;

        // If already computed, return the result from the DP table
        if (dp[i][j] != -1) return dp[i][j];

        // If characters don't match, move `i` forward and keep `j` unchanged
        if (s[i] != t[j]) return dp[i][j] = helper(s, t, i + 1, j, dp);

        // Otherwise, we have two choices:
        // 1. Skip `s[i]` and look for the match in the remaining string
        int notTake = helper(s, t, i + 1, j, dp);
        // 2. Use `s[i]` to match `t[j]` and look for the next character in both strings
        int take = helper(s, t, i + 1, j + 1, dp);

        // Store the result in DP table and return
        return dp[i][j] = take + notTake;
    }

public:
    // Main function to find the number of distinct subsequences
    int numDistinct(string s, string t) {
        // Initialize a DP table with -1 to denote uncomputed states
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        // Call the helper function starting from the beginning of both strings
        return helper(s, t, 0, 0, dp);
    }
};

int main() {
    Solution solution;
    string s = "rabbbit", t = "rabbit";
    cout << "Number of distinct subsequences: " << solution.numDistinct(s, t) << endl;
    return 0;
}

/*
Time Complexity (TC): O(n1 * n2)
- There are `n1` (length of `s`) rows and `n2` (length of `t`) columns in the DP table.
- Each cell is computed at most once.

Space Complexity (SC): O(n1 * n2) for the DP table.
- The recursion stack space is proportional to the length of `s` (O(n1)) but can be optimized in the iterative version.

*/
