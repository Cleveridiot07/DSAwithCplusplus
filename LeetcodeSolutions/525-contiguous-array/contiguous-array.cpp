class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixIndex;
        prefixIndex[0] = -1;
        int prefixSum = 0, maxLength = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += (nums[i] == 0) ? -1 : 1;
            if (prefixIndex.find(prefixSum) != prefixIndex.end()) {
                maxLength = max(maxLength, i - prefixIndex[prefixSum]);
            } else {
                prefixIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};