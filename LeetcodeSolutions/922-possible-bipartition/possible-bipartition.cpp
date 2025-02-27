class Solution {
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()){
                    int cu = q.front();
                    q.pop();
                    for(auto it: graph[cu]){
                        if(color[it] == -1){
                            color[it] = 1 - color[cu];
                            q.push(it);
                        }if(color[it] == color[cu]) return false;
                    }
                }

            }
        }

        return true;
        
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1,vector<int>());
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        return isBipartite(graph);
    }
};

