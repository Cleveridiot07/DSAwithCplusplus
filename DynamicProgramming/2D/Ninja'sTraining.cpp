#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Memoization
// TC= O(Nx3x4)
// SC = O(N) + O(Nx4)

class Solution {
    int helper(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) maxi = max(points[0][i], maxi);
            }
            return maxi;
        }

        if (dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxi = max(maxi, points[day][i] + helper(day - 1, i, points, dp));
            }
        }

        return dp[day][last] = maxi;
    }

public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n - 1, 3, points, dp);
    }
};

// Tabulation
// TC O Nx4x3
// SC O Nx4
int ninjaTraining(int n, vector<vector<int>> &points) {
    // Initialize the DP table
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case: Maximum points on day 0 for each possible "last" task
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    // Fill the DP table for days 1 to n-1
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;  // Initialize to 0 for the current day and last task
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    // Return the maximum points achievable on the last day
    return dp[n - 1][3];
}

int main() {
    Solution solution;
    int n;

    // Input number of days
    cout << "Enter the number of days: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3));

    // Input points for each task on each day
    cout << "Enter the points for each task on each day (space-separated):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> points[i][j];
        }
    }

    // Calculate and output the maximum points
    int result = solution.maximumPoints(points, n);
    cout << "Maximum points that can be earned: " << result << endl;

    return 0;
}
