class Solution {
public:
    vector<vector<int>> createAdjList(int N, vector<vector<int>>& edges) {
        vector<vector<int>> adj(N);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);  // add edge u -> v
            adj[v].push_back(u);  // add edge v -> u (undirected)
        }
        return adj;
    }

    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<vector<int>> adj = createAdjList(N, edges);
        vector<int> ans(N, INT_MAX);
        queue<pair<int, int>> qt;

        qt.push({src, 0});
        ans[src] = 0;

        while (!qt.empty()) {
            int cnode = qt.front().first;
            int clevel = qt.front().second;
            qt.pop();

            for (int neighbor : adj[cnode]) {
                if (ans[neighbor] > clevel + 1) {
                    ans[neighbor] = clevel + 1;
                    qt.push({neighbor, clevel + 1});
                }
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == INT_MAX) ans[i] = -1;
        }

        return ans;
    }
};
