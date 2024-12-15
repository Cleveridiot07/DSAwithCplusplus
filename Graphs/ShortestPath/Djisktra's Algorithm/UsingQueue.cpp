#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto arr: edges){
            adj[arr[0]].push_back({arr[1],arr[2]});
        }
        
        vector<int> Pathcost(V,-1);
        queue<pair<int,int>> qt;
        qt.push({0,0});
        Pathcost[0] = 0;
        while(!qt.empty()){
            int current_weight = qt.front().second;
            int current_node = qt.front().first;
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