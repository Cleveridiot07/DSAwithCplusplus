#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        // Create a DP table with dimensions m x n
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        // Initialize the starting cell
        dp[0][0] = grid[0][0];

        // Fill the first column (only downward movement possible)
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill the first row (only rightward movement possible)
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Calculate the minimum path sum for cell (i, j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        // The bottom-right cell contains the minimum path sum
        return dp[m - 1][n - 1];
    }
};

int main() {
    // Example grid input
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution sol;
    cout << "Minimum Path Sum: " << sol.minPathSum(grid) << endl;

    return 0;
}

/*
Time Complexity: O(m * n)
- We iterate through each cell in the grid exactly once.

Space Complexity: O(m * n)
- A 2D DP table of size m x n is used to store intermediate results.

Explanation of the solution:
1. The DP table (`dp[i][j]`) represents the minimum path sum to reach the cell `(i, j)`.
2. Base case:
   - `dp[0][0]` is initialized as `grid[0][0]`.
   - The first row and first column are filled since they can only be reached from one direction (left or top).
3. For all other cells `(i, j)`, calculate the minimum of the path sums from the top cell (`dp[i-1][j]`) or the left cell (`dp[i][j-1]`), and add the current cell's value (`grid[i][j]`).
4. The result is stored in the bottom-right cell of the DP table (`dp[m-1][n-1]`).

Output Example:
Input Grid:
[
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1]
]

Output:
Minimum Path Sum: 7

Path: 1 → 3 → 1 → 1 → 1
*/
