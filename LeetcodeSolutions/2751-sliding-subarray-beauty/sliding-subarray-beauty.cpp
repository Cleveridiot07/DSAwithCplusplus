

class Solution {
    int findSecondNegative(map<int, int>& mp, int x) {
        if (mp.size() == 0) return 0;
        // if (mp.size() == 1) return mp.begin()->first; 
        int count = 0;
        for (auto it : mp) {
            if (it.first < 0) {
                count  += it.second;
                if (count >= x) {
                    return it.first;  
                }
            }
        }
        return 0; 
    }
    
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 )mp[nums[i]]++;
        
            if (i >= k) {
                if (--mp[nums[i - k]] == 0) {
                    mp.erase(nums[i - k]);
                }
            }

            if (i >= k - 1) {
                ans.push_back(findSecondNegative(mp, x));
            }
        }
        return ans;
    }
};
