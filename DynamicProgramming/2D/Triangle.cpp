#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Initialize dp as a copy of the triangle
        vector<vector<int>> dp = triangle;

        // Traverse from the second row to the last row
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int opt1 = INT_MAX; // Option 1: coming from the left diagonal
                int opt2 = INT_MAX; // Option 2: coming from directly above
                
                if (j - 1 >= 0) opt1 = dp[i][j] + dp[i - 1][j - 1];
                if (j < dp[i - 1].size()) opt2 = dp[i][j] + dp[i - 1][j];
                
                dp[i][j] = min(opt1, opt2); // Take the minimum of both options
            }
        }

        // Return the minimum path sum from the last row
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    
    cout << "Minimum path sum: " << sol.minimumTotal(triangle) << endl;

    return 0;
}

class Solution {
    int helper(vector<vector<int>> &triangle, int level, int i, vector<vector<int>> &dp) {
        // Base case: If we go beyond the last level, return 0 (no more paths to add)
        if (level >= triangle.size()) return 0;

        // If the value is already computed, return it
        if (dp[level][i] != -1) return dp[level][i];

        int mini = INT_MAX;

        // Explore the current level to calculate minimum path sum
        for (int j = 0; j < triangle[level].size(); j++) {
            // Condition: Valid paths are either directly below or diagonal
            if (j - i == 1 || j - i == 0) {
                mini = min(mini, triangle[level][j] + helper(triangle, level + 1, j, dp));
            }
        }

        // Store and return the result
        return dp[level][i] = mini;
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for (auto &arr : triangle) {
            vector<int> temp(arr.size(), -1);
            dp.push_back(temp); // Initialize dp array with -1 (uncomputed states)
        }
        return helper(triangle, 0, 0, dp);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "Minimum path sum (Solution 2): " << sol.minimumTotal(triangle) << endl;
}