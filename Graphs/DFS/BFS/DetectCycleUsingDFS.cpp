bool hasCycle(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<bool>& pathvisited) {
    visited[node] = true;
    pathvisited[node] = true;

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (hasCycle(adj, neighbour, visited, pathvisited))
                return true;
        } else if (pathvisited[neighbour]) {
            return true;
        }
    }

    pathvisited[node] = false;
    return false;
}
