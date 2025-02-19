class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxA = INT_MIN;
        int i = 0, j = nums.size()-1;
        while(i<j){
            int Area = min(nums[i],nums[j])*(j-i);
            maxA = max(maxA,Area);
            if(nums[i]<nums[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxA;        
    }
};