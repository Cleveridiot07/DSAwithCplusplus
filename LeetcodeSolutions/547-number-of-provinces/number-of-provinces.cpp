class Solution {
    void dfs(int n, vector<int>& visited, vector<vector<int>>& isConnected) {
        visited[n] = 1;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[n][i] == 1 && !visited[i]) {
                dfs(i, visited, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;
        
        for (int i = 0; i < n; i++) { 
            if (!visited[i]) {
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};
