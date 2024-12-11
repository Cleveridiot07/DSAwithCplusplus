#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

// Map Approach
// Time Complexity O(n) for travsersing and O(Logn) for fetching and inserting * depend upon the type of map used
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int csum = 0,count = 0;
        mp[0] = 1;

        for(int i=0;i<nums.size();i++){
            csum += nums[i];
            if(mp.find(csum-k) != mp.end()){
                count += mp[csum-k];
            }
            mp[csum]++;
        }

        return count;
    }
};



