#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // My Approach
    vector<int> topKFrequentMyApproach(vector<int>& nums, int k) {
        /*
        Time Complexity (TC):
        - Constructing the map: O(n log n) (as map is balanced binary tree-based).
        - Traversing the map and inserting into the heap: O(n log n).
        - Extracting top k elements from the heap: O(k log n).
        Total: O(n log n).

        Space Complexity (SC):
        - map to store frequencies: O(n).
        - priority_queue for storing elements: O(n).
        Total: O(n).
        */
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> qt;
        while (mp.size() > 0) {
            auto first = *mp.begin();
            qt.push({first.second, first.first});
            mp.erase(first.first);
        }

        vector<int> ans;
        while (k > 0) {
            auto el = qt.top();
            qt.pop();
            ans.push_back(el.second);
            k--;
        }
        return ans;
    }

    // Optimized Approach
    vector<int> topKFrequentOptimized(vector<int>& nums, int k) {
        /*
        Time Complexity (TC):
        - Constructing the frequency map: O(n).
        - Iterating through the map and maintaining a heap: O(n log k).
        - Extracting top k elements from the heap: O(k log k).
        Total: O(n log k).

        Space Complexity (SC):
        - unordered_map to store frequencies: O(n).
        - priority_queue for top k elements: O(k).
        Total: O(n + k).
        */
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove least frequent element
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // My Approach
    cout << "My Approach: ";
    vector<int> resultMyApproach = sol.topKFrequentMyApproach(nums, k);
    for (int num : resultMyApproach) {
        cout << num << " ";
    }
    cout << endl;

    // Optimized Approach
    cout << "Optimized Approach: ";
    vector<int> resultOptimized = sol.topKFrequentOptimized(nums, k);
    for (int num : resultOptimized) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
