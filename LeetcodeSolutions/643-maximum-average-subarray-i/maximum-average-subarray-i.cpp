class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = 0;
        double sum = 0;
        int i = 0,j = 0;
        while(j<k){
            sum+=nums[j];
            j++;
        }
        maxAverage = sum/k;
        while( j < nums.size()){
            sum -= nums[i];
            sum += nums[j];
            maxAverage = max(maxAverage,sum/k);
            i++;
            j++;
        }        
        return maxAverage;
    }
};