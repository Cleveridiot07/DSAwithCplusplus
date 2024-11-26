#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Iterative Solution
class IterativeSolution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill the DP table iteratively
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The final answer is in dp[n1][n2]
        return dp[n1][n2];
    }
    /*
    Time Complexity: O(n1 * n2)
        - Two nested loops iterating over text1 and text2.
    Space Complexity: O(n1 * n2)
        - A 2D DP table of size (n1 + 1) x (n2 + 1).
    */
};

// Recursive Solution (with Memoization)
class RecursiveSolution {
    int helper(string& text1, string& text2, int i1, int i2, vector<vector<int>>& dp) {
        if (i1 < 0 || i2 < 0) return 0;

        if (dp[i1][i2] != -1) return dp[i1][i2];

        if (text1[i1] == text2[i2]) {
            return dp[i1][i2] = 1 + helper(text1, text2, i1 - 1, i2 - 1, dp);
        }

        int opt1 = helper(text1, text2, i1 - 1, i2, dp);
        int opt2 = helper(text1, text2, i1, i2 - 1, dp);

        return dp[i1][i2] = max(opt1, opt2);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return helper(text1, text2, n1 - 1, n2 - 1, dp);
    }
    /*
    Time Complexity: O(n1 * n2)
        - Each subproblem is solved once, and there are n1 * n2 subproblems.
    Space Complexity: O(n1 * n2) + O(n1 + n2)
        - DP table of size n1 x n2.
        - Recursive stack depth of O(n1 + n2) in the worst case.
    */
};

// Main Function
int main() {
    string text1, text2;
    cout << "Enter the first string: ";
    cin >> text1;
    cout << "Enter the second string: ";
    cin >> text2;

    IterativeSolution iterativeSolution;
    RecursiveSolution recursiveSolution;

    cout << "\nUsing Iterative Solution:\n";
    cout << "Longest Common Subsequence Length: " 
         << iterativeSolution.longestCommonSubsequence(text1, text2) << endl;

    cout << "\nUsing Recursive Solution:\n";
    cout << "Longest Common Subsequence Length: " 
         << recursiveSolution.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
