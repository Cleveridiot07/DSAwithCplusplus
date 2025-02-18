class Solution {
    bool binarysearch(vector<int> &arr, int target){
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]<target)s=mid+1;
            else e=mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int e=matrix.size()-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            vector<int> curr = matrix[mid];
            if(curr[0]<=target && curr[curr.size()-1]>=target){
                return binarysearch(curr,target);
            }else if(curr[0]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return false;
        
    }
};