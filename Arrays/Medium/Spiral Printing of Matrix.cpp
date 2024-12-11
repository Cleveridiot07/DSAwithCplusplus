#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> arr;

        int limit = min(m, n) / 2 + min(m, n) % 2;

        for (int level = 0; level < limit; level++) {
            int start = level, end = n - level - 1;
            int up = level, down = m - level - 1;

            for (int i = start; i <= end; i++) 
                arr.push_back(matrix[up][i]);

            for (int i = up + 1; i <= down; i++) 
                arr.push_back(matrix[i][end]);

            if (up != down) {
                for (int i = end - 1; i >= start; i--) 
                    arr.push_back(matrix[down][i]);
            }

            if (start != end) {
                for (int i = down - 1; i > up; i--) 
                    arr.push_back(matrix[i][start]);
            }
        }

        return arr;
    }
};
