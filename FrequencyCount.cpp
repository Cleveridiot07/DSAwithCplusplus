#include<iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<ans.size();i++){
            ans[i] = mp[i+1];
        }
        return ans;
    }
};
