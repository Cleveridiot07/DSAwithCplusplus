class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp;
        for(auto arr: matrix){
            dp.push_back(arr);
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int opt1 = dp[i][j] + dp[i-1][j];
                int opt2 = INT_MAX;
                int opt3 = INT_MAX;
                if(j-1 >= 0) opt2 = dp[i][j] + dp[i-1][j-1];
                if(j+1 < n) opt3 = dp[i][j] + dp[i-1][j+1];

                dp[i][j] = min(opt1,min(opt2,opt3)); 
            }
        }

        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};