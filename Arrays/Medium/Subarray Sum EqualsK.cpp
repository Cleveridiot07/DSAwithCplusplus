#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

// For positives only Two Pointer Approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0, csum = 0, count = 0;
        int n = nums.size();

        while (j < n) {
            csum += nums[j];

            while (csum > k && i <= j) {
                csum -= nums[i];
                i++;
            }

            if (csum == k) {
                count++;
            }

            j++;
        }

        return count;
    }
};


