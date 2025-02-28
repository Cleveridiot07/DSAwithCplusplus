class Solution {
public:
    string shortestCommonSupersequence(string s, string sr) {
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

        int i = n1, j = n2;
        string result = "";
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




       