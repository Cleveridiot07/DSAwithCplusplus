class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& arr : times) {
            adj[arr[0]].push_back({arr[1], arr[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,k});

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;

        while(!pq.empty()){
            int currentTime = pq.top().first;
            int currentStop = pq.top().second;
            pq.pop();

            for(auto neighbor: adj[currentStop]){
                int nextStopTime = currentTime + neighbor.second;
                int nextStop = neighbor.first;
                if(dist[nextStop] > nextStopTime){
                    dist[nextStop] = nextStopTime;
                    pq.push({nextStopTime,nextStop});
                }
            }
        }

        int result = *max_element(dist.begin() + 1, dist.end());
        return result == INT_MAX ? -1 : result;
    }
};