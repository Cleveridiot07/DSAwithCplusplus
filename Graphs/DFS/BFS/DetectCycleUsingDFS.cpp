bool hasCycle(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<bool> pathvisited)
{
    visited[node] = true;
    pathvisited[node] = true;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (hasCycle(adj, i, visited, pathvisited))
                return true;
        }
        else if (pathvisited[neighbour] = true)
            return true;
    }
    pathvisited[i] = false;
    return false;
}