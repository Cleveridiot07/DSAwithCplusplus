class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i =  nums.size()-1;i>0;i--){
            int j = 0;
            int k = i-1;
            while(j<k){
                if(nums[j] + nums[k] > nums[i]){
                    count += k-j;
                    k--;
                }else{
                    j++;
                }
            }
        }
        return count;
    }
};