class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int mul = 1, count = 0, i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            mul *= nums[j];

            while (mul >= k) {
                mul /= nums[i];
                i++;
            }
            
            count += (j - i + 1);
        }
        
        return count;
    }
};
