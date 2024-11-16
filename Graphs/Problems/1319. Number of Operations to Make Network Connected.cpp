class DisjointSet {
    vector<int> rank, uparent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        uparent.resize(n, 0);
        for (int i = 0; i < n; i++)
            uparent[i] = i;
    }

    int findUparent(int node) {
        if (node == uparent[node])
            return node;
        return uparent[node] = findUparent(uparent[node]);
    }

    void UnionByRank(int node1, int node2) {
        int up1 = findUparent(node1);
        int up2 = findUparent(node2);

        if (up1 == up2)
            return;

        if (rank[up1] < rank[up2]) {
            uparent[up1] = up2;
        } else if (rank[up1] > rank[up2]) {
            uparent[up2] = up1;
        } else {
            uparent[up1] = up2;
            rank[up2]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1; 

        DisjointSet ds(n);
        int extraCables = 0;

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            if (ds.findUparent(u) == ds.findUparent(v)) {
                extraCables++; 
            } else {
                ds.UnionByRank(u, v); 
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUparent(i) == i) {
                components++;
            }
        }

        if (extraCables >= components - 1)
            return components - 1;

        return -1; 
    }
};
