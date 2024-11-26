#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minDistance(std::string s, std::string sr) {
        int n1 = s.size(), n2 = sr.size();
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == sr[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int ans = (n1 - dp[n1][n2]) + (n2 - dp[n1][n2]);
        return ans;
    }
};

int main() {
    Solution sol;
    std::string s = "sea";
    std::string sr = "eat";
    std::cout << "Minimum Number of Operations to Convert: " << sol.minDistance(s, sr) << std::endl;
    return 0;
}

/*
Time Complexity: O(n1 * n2), where n1 and n2 are the lengths of s and sr. The nested loops iterate through both strings.
Space Complexity: O(n1 * n2), due to the dp array storing results for substrings of s and sr.
*/
