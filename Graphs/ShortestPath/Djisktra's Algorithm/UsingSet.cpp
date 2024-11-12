class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        int V = adj.size();
        vector<int> Pathcost(V, INT_MAX);
        Pathcost[src] = 0;
        set<pair<int, int>> st;
        st.insert({0, src});

        while (!st.empty())
        {
            int current_weight = st.begin()->first;
            int current_node = st.begin()->second;
            st.erase(st.begin());
            for (auto &neighbor : adj[current_node])
            {
                int next_node = neighbor.first;
                int edge_weight = neighbor.second;
                if (Pathcost[next_node] > current_weight + edge_weight)
                {
                    if (Pathcost[next_node] != INT_MAX)
                    {
                        st.erase({Pathcost[next_node], next_node});
                    }
                    Pathcost[next_node] = current_weight + edge_weight;
                    st.insert({Pathcost[next_node], next_node});
                }
            }
        }

        for (int &cost : Pathcost)
        {
            if (cost == INT_MAX)
                cost = -1;
        }

        return Pathcost;
    }
};
