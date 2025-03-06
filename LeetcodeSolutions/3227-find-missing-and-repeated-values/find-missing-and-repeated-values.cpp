class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> adj(grid.size()*grid.size() + 1);
        int rep= -1;
        for(auto it: grid){
            for(int ij: it){
                adj[ij]++;
                if(adj[ij]>=2) rep = ij;
            }
        }
        int rem = -1;
        for(int i=1;i<adj.size();i++){
            if(adj[i] == 0) rem = i;
        }

        return {rep,rem};
    }
};