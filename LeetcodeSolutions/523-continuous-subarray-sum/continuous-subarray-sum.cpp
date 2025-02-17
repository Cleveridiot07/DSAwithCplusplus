class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i+1] = (pref[i] + nums[i]) % k;
        }
        unordered_map<int, int> m; 
        for (int i = 0; i < n + 1; ++i) {
            if (m.find(pref[i]) != m.end()) {
                if (i - m[pref[i]] > 1) {
                    return true;
                }
            } else {
                m[pref[i]] = i;
            }
        }
        return false;      
    }
};