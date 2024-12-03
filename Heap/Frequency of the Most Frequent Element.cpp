#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi = INT_MIN;
        for(int i= nums.size()-1;i>=0;i--){
            int temp = k;
            int j = i-1;
            int count = 1;
            while(temp>0 && j>=0){
                if(nums[i]-nums[j] <= temp){
                    temp = temp - (nums[i]-nums[j]);
                    count++;
                    j--;
                }else{
                    break;
                }
            }
            maxi = max(maxi,count);
        }
        
        return maxi;
    }
};