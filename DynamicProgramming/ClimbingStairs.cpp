#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int ways(int n, vector<int> &dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = ways(n - 1, dp) + ways(n - 2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dparray(n + 1, -1);
        return ways(n, dparray);
    }
};

int main() {
    Solution solution;
    int n;

    // Input number of steps
    cout << "Enter the number of steps: ";
    cin >> n;

    // Calculate the number of ways to climb stairs
    int result = solution.climbStairs(n);

    // Output the result
    cout << "Number of ways to climb " << n << " steps: " << result << endl;

    return 0;
}
