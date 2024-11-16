#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet
{
    vector<int> size, uparent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
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

    void UnionBysize(int node1, int node2)
    {
        int up1 = findUparent(node1);
        int up2 = findUparent(node2);

        if (up1 == up2)
            return;

        if (size[up1] < size[up2])
        {
            uparent[up1] = up2;
            size[up2] += size[up1];
        }
        else if (size[up1] > size[up2])
        {
            uparent[up2] = up1;
            size[up1] += size[up2];
        }
        else
        {
            uparent[up1] = up2;
            size[up2] += size[up1];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    return 0;
}