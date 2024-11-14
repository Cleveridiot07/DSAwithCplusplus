class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto& arr : roads) {
            adj[arr[0]].push_back({arr[1], arr[2]});
            adj[arr[1]].push_back({arr[0], arr[2]});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        
        vector<long long> pathCount(n, 0);
        pathCount[0] = 1;

        while (!pq.empty()) {
            long long currentTime = pq.top().first;
            int currentStop = pq.top().second;
            pq.pop();

            for (auto neighbor : adj[currentStop]) {
                int nextStop = neighbor.first;
                long long nextStopTime = currentTime + neighbor.second;

                if (dist[nextStop] > nextStopTime) {
                    dist[nextStop] = nextStopTime;
                    pathCount[nextStop] = pathCount[currentStop];
                    pq.push({nextStopTime, nextStop});
                }
                else if (dist[nextStop] == nextStopTime) {
                    pathCount[nextStop] = (pathCount[nextStop] + pathCount[currentStop]) % MOD;
                }
            }
        }

        return pathCount[n-1];
    }
};
