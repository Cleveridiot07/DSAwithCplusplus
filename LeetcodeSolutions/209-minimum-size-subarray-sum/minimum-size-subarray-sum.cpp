class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, mini = INT_MAX;

        while (j < nums.size()) {
            sum += nums[j++];

            while (sum >= target) {
                mini = min(mini, j - i);
                sum -= nums[i++];
            }
        }
        
        return mini == INT_MAX ? 0 : mini;
    }
};
