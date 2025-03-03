

class Solution {
public:
    int longestPalindromicSubsequence(string str, int maxOperations) {
        int len = str.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(maxOperations + 1, 0)));

        for (int i = 0; i < len; i++) {
            for (int remainingOps = 0; remainingOps <= maxOperations; remainingOps++) {
                dp[i][i][remainingOps] = 1;
            }
        }

        for (int subStrLength = 2; subStrLength <= len; subStrLength++) {
            for (int start = 0; start <= len - subStrLength; start++) {
                int end = start + subStrLength - 1;
                for (int remainingOps = 0; remainingOps <= maxOperations; remainingOps++) {
                    if (str[start] == str[end]) {
                        dp[start][end][remainingOps] = 2 + dp[start + 1][end - 1][remainingOps];
                    } else {
                        int case1 = dp[start + 1][end][remainingOps];
                        int case2 = dp[start][end - 1][remainingOps];
                        int case3 = 0;
                        int charDifference = min(abs(str[start] - str[end]), 26 - abs(str[start] - str[end]));
                        if (charDifference <= remainingOps) {
                            case3 = 2 + dp[start + 1][end - 1][remainingOps - charDifference];
                        }
                        dp[start][end][remainingOps] = max({case1, case2, case3});
                    }
                }
            }
        }

        return dp[0][len - 1][maxOperations];
    }
};
