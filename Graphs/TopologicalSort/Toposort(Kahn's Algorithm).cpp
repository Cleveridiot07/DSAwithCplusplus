#include <iostream>
#include <vector>
#include <queue>
// Kahn's
using namespace std;
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> indegree(adj.size(),0);
        for(auto a: adj){
            for(int c:  a){
                indegree[c]++;
            }
        }
        queue<int> qt;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) qt.push(i);
        }

        vector<int> ans;
        while(!qt.empty()){
            int front = qt.front();
            qt.pop();
            ans.push_back(front);
            for(int i: adj[front]){
                indegree[i]--;
                if(indegree[i]==0) qt.push(i);
            }
        }
        return ans;
        
    }