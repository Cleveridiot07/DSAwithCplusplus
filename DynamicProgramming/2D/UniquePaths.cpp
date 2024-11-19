#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a dp table with dimensions m x n and initialize with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the first row with 1 (only one way to move right)
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        // Initialize the first column with 1 (only one way to move down)
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp table using the recurrence relation:
        // dp[i][j] = dp[i-1][j] + dp[i][j-1]
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the number of unique paths to reach the bottom-right cell
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 3, n = 7; // Example: 3x7 grid
    Solution sol;
    cout << "Number of unique paths in a " << m << "x" << n << " grid: "
         << sol.uniquePaths(m, n) << endl;
    return 0;
}

/*
Time Complexity: O(m * n)
- Nested loops iterate through all m rows and n columns to compute the dp table.
- Total number of computations is proportional to the number of cells in the grid: O(m * n).

Space Complexity: O(m * n)
- A 2D dp table of size m x n is used to store results for all cells in the grid.
- Additional constant space is used for variables in the function.
- Total space complexity is O(m * n).

Overall:
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
