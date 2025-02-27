class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int i = entrance[0];
        int j = entrance[1];

        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> qt;
        qt.push({i, j});
        visited[i][j] = true;

        int level = 0;
        vector<int> directions = {-1, 0, 1, 0, -1, 0}; 
        
        while (!qt.empty()) {
            int s = qt.size();
            for (int k = 0; k < s; k++) {
                auto [x, y] = qt.front();
                qt.pop();

              
                if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && (x != entrance[0] || y != entrance[1])) {
                    return level;
                }

               
                for (int d = 0; d < 4; d++) {
                    int newX = x + directions[d];
                    int newY = y + directions[d + 1];

            
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] == '.' && !visited[newX][newY]) {
                        qt.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
            level++; 
        }

        return -1;
    }
};