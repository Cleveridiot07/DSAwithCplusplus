class Solution {
private:
    int pivot(vector<int> &nums){
        int s = 0,e=nums.size()-1,n=nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]>nums[mid+1])
                return mid;
            else{
                if(nums[mid]<=nums[n])e=mid-1;
                else s= mid+1;
            }
        }
        return n;
        }
    int binarysearch(vector<int>& nums,int s,int e,int target){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(target==nums[0])return 0;
            else return -1;
        } 
        int piv = pivot(nums);
        int fh = binarysearch(nums, 0, piv, target);
        int sh = binarysearch(nums, piv + 1, nums.size() - 1, target);
        if (fh != -1) {
            return fh;
        }
        if (sh != -1) {
            return sh;
        }
        return -1;
    }
};