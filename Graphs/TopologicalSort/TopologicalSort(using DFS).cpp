#include <iostream>
#include <vector>
#include <queue>
#include <stack>
vector<int> topologicalSort(vector<vector<int>>& adj) {
    stack<int> ans;  // To store the topologically sorted nodes
    vector<bool> visited(adj.size(), false);  // To track visited nodes
    
    // Perform DFS for each unvisited node
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, ans);
        }
    }

    // Convert stack to vector for final answer
    vector<int> result;
    while (!ans.empty()) {
        result.push_back(ans.top());
        ans.pop();
    }
    return result;
}

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& ans) {
    visited[node] = true;
    // Visit all the adjacent nodes
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, ans);
        }
    }
    // Push the current node to the stack after exploring all its neighbors
    ans.push(node);
}
