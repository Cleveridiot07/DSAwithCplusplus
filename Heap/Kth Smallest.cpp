#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(std::vector<int>& nums, int k) {
        // Create a min-heap from the array
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());
        
        // Pop the first (k-1) smallest elements
        for (int i = 1; i < k; i++) {
            minHeap.pop();
        }

        // The k-th smallest element is now at the top
        return minHeap.top();
    }
};

int main() {
    // Input array
    std::vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3; // Find the 3rd smallest element

    Solution sol;
    int result = sol.kthSmallest(arr, k);

    std::cout << "The " << k << "-th smallest element is: " << result << std::endl;

    return 0;
}
