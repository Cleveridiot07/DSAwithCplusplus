class Solution {
public:
    int findLHS(vector<int>& nums) {
       sort(nums.begin(), nums.end());

       int l = 0;
       int res = 0;
       for(int r = 0 ; r < nums.size() ; r++){
        while(nums[r] - nums[l] > 1){
            l += 1;
        }
        if(nums[r] - nums[l] == 1){
            res = max(res, r - l + 1);
        }
       }
       return res;
    }
};