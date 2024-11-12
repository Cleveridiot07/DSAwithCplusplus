class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto arr: edges){
            adj[arr[0]].push_back({arr[1],arr[2]});
        }
        
        vector<int> Pathcost(V,-1);
        // Min-heap to process nodes with the smallest path cost first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qt;
        qt.push({0,0});
        Pathcost[0] = 0;
        while(!qt.empty()){
            int current_weight = qt.top().second;
            int current_node = qt.top().first;
            qt.pop();
            for(auto arr: adj[current_node]){
                if(Pathcost[arr.first] == -1 || Pathcost[arr.first] > current_weight + arr.second ){
                    Pathcost[arr.first] = current_weight + arr.second;
                }else{
                    continue;
                }
                qt.push({arr.first,current_weight + arr.second});
            }
        }
        return Pathcost;
    }
};