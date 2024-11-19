#include <iostream>
#include <vector>
using namespace std;

// Memoization
class Solution {
    // Recursive helper function with memoization
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp) {
        // Base Cases
        if (i == 0 && j == 0) return 1;  // Reached the start of the grid
        if (i < 0 || j < 0) return 0;    // Out of bounds, no valid path

        // Return precomputed value if already solved
        if (dp[i][j] != -1) return dp[i][j];

        // Compute the number of unique paths by moving up and left
        int up = helper(i - 1, j, m, n, dp);
        int left = helper(i, j - 1, m, n, dp);

        // Store the result in dp table and return it
        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n) {
        // Initialize dp table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Start the recursion from the bottom-right cell
        return helper(m - 1, n - 1, m, n, dp);
    }
};


/*
Time Complexity: O(m * n)
- Each cell in the dp table is computed at most once due to memoization.
- There are m rows and n columns, so the total number of computations is O(m * n).

Space Complexity: O(m * n) + O(m + n)
- O(m * n) for the dp table to store results.
- O(m + n) for the recursion stack in the worst case (diagonal traversal of the grid).
- Total space complexity is O(m * n).

Overall:
Time Complexity: O(m * n)
Space Complexity: O(m * n) + stack space
*/



// Tabulation

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
Space Complexity: O(m * n) + no stack space
*/



// Main function to test the solution
int main() {
    int m = 3, n = 7; // Example: 3x7 grid
    Solution sol;
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " 
         << sol.uniquePaths(m, n) << endl;
    return 0;
}