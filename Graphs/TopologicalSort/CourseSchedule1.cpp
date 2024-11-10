class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> qt;

        for (auto c : pre) {
            adj[c[1]].push_back(c[0]);
            indegree[c[0]]++;
        }

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) qt.push(i);
        }

        int count = 0;
        while (!qt.empty()) {
            int front = qt.front();
            qt.pop();
            count++;

            for (int neighbor : adj[front]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) qt.push(neighbor);
            }
        }

        return count == numCourses;
    }
};
