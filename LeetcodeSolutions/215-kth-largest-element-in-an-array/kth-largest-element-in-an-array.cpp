class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());

        vector<int> count(max-min+1, 0);
        for (auto n : nums) {
            count[n-min]++;
        }
        int c = 0;
        int res = 0;
        for (int i=max; i >= min; --i) {
            if (count[i-min]) {
                c += count[i-min];
                if (c >= k) {
                    res = i;
                    break;
                }
            }
        }
        return res;
    }
};