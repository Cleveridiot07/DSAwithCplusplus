class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int csum = 0;
        mp[csum]++;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            csum += nums[i];
            if(mp.find(csum-k) != mp.end()) count += mp[csum-k];
            mp[csum]++;
        }

        return count;
    }
};