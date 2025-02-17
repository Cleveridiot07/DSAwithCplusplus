class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int el  = nums[i];
            if(mp.find(target-el) != mp.end()){
                return {mp[target-el],i};
            }
            mp[el] = i;
        }
        return {-1,-1};
    }
};