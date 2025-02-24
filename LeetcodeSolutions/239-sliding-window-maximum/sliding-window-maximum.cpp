class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ms.insert(nums[i]);
            if(i >= k-1){
                ans.push_back(*ms.rbegin());
                std::multiset<int>::iterator it = ms.find(nums[i-k+1]);
                ms.erase(it);
            }
        }

        return ans;
    }
};