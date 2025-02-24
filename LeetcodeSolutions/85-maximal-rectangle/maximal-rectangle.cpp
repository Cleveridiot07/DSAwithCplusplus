class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);  
        int maxArea = 0;
        auto calculateMaxArea = [](const vector<int>& heights) {
            stack<int> s;
            int maxArea = 0;
            int n = heights.size();
            
            for (int i = 0; i <= n; i++) {
                int h = (i == n) ? 0 : heights[i];
                while (!s.empty() && h < heights[s.top()]) {
                    int height = heights[s.top()];
                    s.pop();
                    int width = s.empty() ? i : i - s.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                s.push(i);
            }
            return maxArea;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            
            maxArea = max(maxArea, calculateMaxArea(heights));
        }
        
        return maxArea;
    }
};
