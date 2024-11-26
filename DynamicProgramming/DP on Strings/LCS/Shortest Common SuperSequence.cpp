#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    std::string shortestCommonSupersequence(std::string s, std::string sr) {
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

        int i = n1, j = n2;
        std::string result = "";

        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && s[i - 1] == sr[j - 1]) {
                result += s[i - 1];
                i--;
                j--;
            } else if (j > 0 && (i == 0 || dp[i][j - 1] >= dp[i - 1][j])) {
                result += sr[j - 1];
                j--;
            } else {
                result += s[i - 1];
                i--;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// Example Usage
int main() {
    Solution sol;
    std::string s = "abac";
    std::string sr = "cab";
    cout << "Shortest Common Supersequence: " << sol.shortestCommonSupersequence(s, sr) << endl;
    return 0;
}

/*
Time Complexity: O(n1 * n2), where n1 and n2 are the lengths of s and sr. The nested loops calculate the dp table, and the backtracking runs in O(n1 + n2).
Space Complexity: O(n1 * n2), for storing the dp table.
*/
