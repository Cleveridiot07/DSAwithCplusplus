class Solution {
    void helper(vector<vector<int>> &output,unordered_map<int,int> mp,vector<int> pre,int n,int index){
        if(index >= n){
            output.push_back(pre);
            return;
        }

        for(auto& it:mp){
            if(it.second > 0){
                pre.push_back(it.first);
                it.second--;
                helper(output,mp,pre,n,index+1);
                pre.pop_back();
                it.second++;
            }
        }

        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums) mp[it]++;
        vector<vector<int>> ans;
        helper(ans,mp,{},nums.size(),0);
        return ans;
    }
};