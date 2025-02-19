class Solution {
    bool helper(vector<int>& nums, int target,int s,int e){
        if(s>e) return false;
        int mid = s + (e-s)/2;
        if(nums[mid]==target) return true;
        if(nums[s] == nums[mid] && nums[mid] == nums[e]){
            return helper(nums,target,s,mid-1) || helper(nums,target,mid+1,e);
        }
        if(nums[s] <= nums[mid]){
            if(nums[s] <= target && nums[mid] > target) return helper(nums,target,s,mid-1);
            else return helper(nums,target,mid+1,e);
        }else{
            if(nums[mid] < target && nums[e] >= target) return helper(nums,target,mid+1,e);
            else return helper(nums,target,s,mid-1);
        }

        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        return helper(nums,target,0,nums.size()-1);
    }
};