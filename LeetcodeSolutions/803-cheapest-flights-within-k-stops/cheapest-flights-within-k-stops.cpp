class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& arr : flights) {
            adj[arr[0]].push_back({arr[1], arr[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX));
        minCost[src][0] = 0;

        while (!pq.empty()) {
            auto arr = pq.top();
            pq.pop();

            int fairTillCS = arr[0];
            int currentStop = arr[1];
            int noOfPstops = arr[2];

            if (currentStop == dst) return fairTillCS;

            if (noOfPstops > k) continue;

            for (auto& neighbor : adj[currentStop]) {
                int nextStop = neighbor.first;
                int nextCost = fairTillCS + neighbor.second;

                if (nextCost < minCost[nextStop][noOfPstops + 1]) {
                    minCost[nextStop][noOfPstops + 1] = nextCost;
                    pq.push({nextCost, nextStop, noOfPstops + 1});
                }
            }
        }
        
        return -1;
    }
};
