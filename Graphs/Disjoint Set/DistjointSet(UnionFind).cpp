#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet
{
    vector<int> rank, uparent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        uparent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            uparent[i] = i;
    }

    bool isSameSet(int a, int b)
    {
        return uparent[a] == uparent[b];
    }

    int findUparent(int node)
    {
        if (node == uparent[node])
            return node;
        return uparent[node] = findUparent(uparent[node]);
    }

    void UnionByRank(int node1, int node2)
    {
        int up1 = findUparent(node1);
        int up2 = findUparent(node2);

        if (up1 == up2)
            return;

        if (rank[up1] < rank[up2])
        {
            uparent[up1] = up2;
        }
        else if (rank[up1] > rank[up2])
        {
            uparent[up2] = up1;
        }
        else
        {
            uparent[up1] = up2;
            rank[up2]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    return 0;
}