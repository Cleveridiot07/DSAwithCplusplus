class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {0, 0}));
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    int length = (j > 0) ? dp[i][j - 1].first + 1 : 1;
                    int breadth = (i > 0) ? dp[i - 1][j].second + 1 : 1;
                    dp[i][j] = {length, breadth};

                    int minWidth = length;
                    for (int k = 0; k < breadth; k++) {
                        minWidth = min(minWidth, dp[i - k][j].first);
                        maxArea = max(maxArea, minWidth * (k + 1));
                    }
                }
            }
        }
        return maxArea;
    }
};
