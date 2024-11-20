#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Initialize DP table with the values of the original matrix
        vector<vector<int>> dp = matrix;

        // Start processing from the second row to the last row
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int opt1 = dp[i][j] + dp[i - 1][j]; // Directly above
                int opt2 = INT_MAX;
                int opt3 = INT_MAX;

                // Check for valid left diagonal (j - 1)
                if (j - 1 >= 0) opt2 = dp[i][j] + dp[i - 1][j - 1];

                // Check for valid right diagonal (j + 1)
                if (j + 1 < n) opt3 = dp[i][j] + dp[i - 1][j + 1];

                // Update DP table with the minimum of the three options
                dp[i][j] = min(opt1, min(opt2, opt3));
            }
        }

        // The result is the minimum value in the last row
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    cout << "Minimum Falling Path Sum: " << sol.minFallingPathSum(matrix) << endl;

    return 0;
}
