class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, count = 0;

        while (j < nums.size()) {
            if (i == j || nums[j] - nums[i] < k) {
                j++;
            } else if (nums[j] - nums[i] > k) {
                i++;
            } else {
                count++;
                j++;
                while (j < nums.size() && nums[j] == nums[j - 1]) j++;
            }
        }

        return count;
    }
};
