class Solution {
public:
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, m, n);
    }

    int helper(string &word1, string &word2, int i, int j) {
        if (i == 0) return j;
        if (j == 0) return i;
        
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = helper(word1, word2, i - 1, j - 1);
        } else {
            return dp[i][j] = min({
                helper(word1, word2, i, j - 1) + 1,
                helper(word1, word2, i - 1, j) + 1,
                helper(word1, word2, i - 1, j - 1) + 1
            });
        }
    }
};
