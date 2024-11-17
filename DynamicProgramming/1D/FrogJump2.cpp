#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
    int minJ(int n, int k, vector<int> &height, vector<int>& dp) {
        if (n == 0) return 0;
        if (dp[n] != INT_MAX) return dp[n];
        
        int loop = min(n, k);
        int mini = INT_MAX;
        for (int i = 1; i <= loop; i++) {
            mini = min(mini, minJ(n - i, k, height, dp) + abs(height[n] - height[n - i]));
        }
        return dp[n] = mini;
    }
    
public:
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> dp(arr.size(), INT_MAX);
        return minJ(arr.size() - 1, k, arr, dp);
    }
};

int main() {
    Solution solution;
    int n, k;

    // Input number of stones and maximum jump distance
    cout << "Enter the number of stones: ";
    cin >> n;
    cout << "Enter the maximum jump distance (k): ";
    cin >> k;

    vector<int> arr(n);

    // Input the heights of the stones
    cout << "Enter the heights of the stones: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Calculate the minimum cost to reach the last stone
    int result = solution.minimizeCost(k, arr);

    // Output the result
    cout << "Minimum cost to reach the last stone: " << result << endl;

    return 0;
}
