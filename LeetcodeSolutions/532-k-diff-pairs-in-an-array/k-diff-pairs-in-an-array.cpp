class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0, j = 0;
        int count = 0;
        while(i <= j && j < nums.size()){
            int curr = abs(nums[j] - nums[i]);
            if(i == j || curr < k){
                j++;
            }
            else if(curr == k){ 
                count++;
                j++;
                while(j < nums.size() && nums[j] == nums[j-1]) j++;
                continue;
            }else{
                i++;
            }
        } 

        return count;
    }
};