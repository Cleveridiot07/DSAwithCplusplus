#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
    private:
        int minJ(int n, vector<int> &height, vector<int> &dp) {
            if (n == 0) return 0;
            
            if (dp[n] != -1) return dp[n];
            
            int left = minJ(n - 1, height, dp) + abs(height[n] - height[n - 1]);
            int right = INT_MAX;
            if (n > 1) 
                right = minJ(n - 2, height, dp) + abs(height[n] - height[n - 2]);
            
            return dp[n] = min(left, right);
        }
    
    public:
        int minimumEnergy(vector<int>& height, int n) {
            vector<int> dp(n + 1, -1);
            return minJ(n - 1, height, dp);
        }
};

int main() {
    Solution solution;
    int n;

    // Input number of stones
    cout << "Enter the number of stones: ";
    cin >> n;

    vector<int> height(n);

    // Input the heights of the stones
    cout << "Enter the heights of the stones: ";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    // Calculate the minimum energy required
    int result = solution.minimumEnergy(height, n);

    // Output the result
    cout << "Minimum energy required: " << result << endl;

    return 0;
}
