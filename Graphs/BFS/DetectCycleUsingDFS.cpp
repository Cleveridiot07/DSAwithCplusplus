#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;
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
