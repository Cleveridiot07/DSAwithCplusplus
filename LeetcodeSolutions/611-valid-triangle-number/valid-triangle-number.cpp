class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = 0;
        int ans = 0;
        while(index < nums.size() && nums[index] == 0  ) index++;
        for(int i=index;i<nums.size();i++){
            for(int j = i+1;j<nums.size()-1;j++){
                auto it = lower_bound(nums.begin(),nums.end(),nums[i] + nums[j]) - (nums.begin() + j);
                ans += it-1;
            }
        }

        return ans;
    }
};