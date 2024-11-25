#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string sr = s;
        reverse(sr.begin(), sr.end());
        int n1 = s.size(), n2 = sr.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == sr[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence: " << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}

/*
Time Complexity: O(n^2), where n is the length of the string. The nested loops iterate through the string.
Space Complexity: O(n^2), due to the dp array storing results for substrings of s and its reverse.
*/
