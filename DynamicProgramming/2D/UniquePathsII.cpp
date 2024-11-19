#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        // If the starting cell has an obstacle, no paths are possible
        if (og[0][0] == 1) return 0;

        int n = og.size();    // Number of rows
        int m = og[0].size(); // Number of columns

        // Initialize a DP table with dimensions n x m and set all values to 0
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // The starting cell is reachable
        dp[0][0] = 1;

        // Fill the first column while checking for obstacles
        for (int i = 1; i < n; i++) {
            if (og[i][0] == 1) break; // If an obstacle is encountered, stop filling
            dp[i][0] = dp[i - 1][0]; // Carry forward the value from the cell above
        }

        // Fill the first row while checking for obstacles
        for (int j = 1; j < m; j++) {
            if (og[0][j] == 1) break; // If an obstacle is encountered, stop filling
            dp[0][j] = dp[0][j - 1]; // Carry forward the value from the cell to the left
        }

        // Fill the rest of the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // If the current cell is an obstacle, skip it
                if (og[i][j] == 1) continue;

                // Add the number of ways from the cell above and the cell to the left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the number of unique paths to the bottom-right corner
        return dp[n - 1][m - 1];
    }
};

int main() {
    vector<vector<int>> og = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution sol;
    cout << "Number of unique paths with obstacles: " 
         << sol.uniquePathsWithObstacles(og) << endl;

    return 0;
}

/*
Time Complexity: O(m * n)
- Nested loops iterate through all cells in the grid.

Space Complexity: O(m * n)
- A 2D DP table is used to store the number of unique paths to each cell.

Overall:
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
