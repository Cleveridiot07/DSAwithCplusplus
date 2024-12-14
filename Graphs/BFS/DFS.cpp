vector<int> dfs(vector<vector<int>> &graph)
{
    stack<int> st;
    vector<bool> visited(graph.size(), false);
    vector<int> ans;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
            st.push(i);
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            ans.push_back(top);
            visited[top] = true;
            for (int c : graph[top])
            {
                if (!visited[c])
                    st.push(c);
            }
        }
    }
    return ans;
}