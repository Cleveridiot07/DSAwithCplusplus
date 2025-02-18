class Solution {
    bool check(int currentSum, vector<int>& nums, int k) {
        int count = 1; 
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (sum > currentSum) {
                count++;
                sum = nums[i];
            }
            
            if (count > k) return false; 
        }
        
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int maxi = -1;
        

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }

        int low = maxi, high = sum;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (check(mid, nums, k)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
