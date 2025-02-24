#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; 
        vector<int> result;
        
        for (int j = 0; j < nums.size(); j++) {
            pq.push({nums[j], j});
            if (j >= k - 1) {
                while (pq.top().second <= j - k) {
                    pq.pop();
                }
                result.push_back(pq.top().first);
            }
        }
        
        return result;
    }
};
