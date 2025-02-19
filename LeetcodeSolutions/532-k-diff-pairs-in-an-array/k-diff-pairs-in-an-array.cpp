class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0, j = 0;
        int count = 0;
        while(i <= j && j < nums.size()){
            if(i == j || nums[j] - nums[i] < k){
                j++;
            }
            else if(nums[j] - nums[i] == k){ 
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