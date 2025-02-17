class NumMatrix {
    vector<vector<int>> rowPrefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        rowPrefix = matrix;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                rowPrefix[i][j] += rowPrefix[i][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += rowPrefix[i][col2] - (col1 > 0 ? rowPrefix[i][col1 - 1] : 0);
        }
        return sum;
    }
};
