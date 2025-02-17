class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int mini = INT_MAX;
        int sum = 0;
        while(i<=j && j<nums.size()){
            if(sum >= target){
                mini = min(mini,j-i);
                sum -= nums[i];
                i++;
            }
            else{
                sum += nums[j];
                j++;
            }
        }

        while(i<j){
            if(sum >= target){
                mini = min(mini,j-i);
                sum -= nums[i];
                i++;
            }else break;
        }

        return mini == INT_MAX ? 0 : mini;
    }
};