#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minInsertions(std::string s) {
        std::string sr = s;
        std::reverse(sr.begin(), sr.end());
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
        return n1 - dp[n1][n2];
    }
};

int main() {
    Solution sol;
    std::string s = "mbadm";
    std::cout << "Minimum Insertions to Make Palindrome: " << sol.minInsertions(s) << std::endl;
    return 0;
}

/*
Time Complexity: O(n^2), where n is the length of the string. The nested loops iterate through the string.
Space Complexity: O(n^2), due to the dp array storing results for substrings of s and its reverse.
*/
