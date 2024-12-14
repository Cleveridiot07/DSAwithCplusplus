class Solution {
public:
    void dfs(int node , unordered_map<int,list<int>> &adj , unordered_map<int,bool> &visited){

        visited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour , adj , visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //create an adjacency list
        unordered_map<int,list<int>> adj;
        int n = isConnected.size();
        int m = isConnected[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i != j && isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        //as it is a disconnected graph, use for loop
        int count = 0;
        unordered_map<int,bool> visited;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i , adj , visited);
                count++;
            }
        }

        return count;
    }
};