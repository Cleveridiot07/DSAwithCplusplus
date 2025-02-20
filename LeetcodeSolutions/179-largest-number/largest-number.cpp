class Solution {
    static bool comparator(string a,string b){
        return a+b < b+a;
    }

public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto it:nums) arr.push_back(to_string(it));
        sort(arr.begin(),arr.end(),Solution::comparator);
        string ans = "";
        for( int i=arr.size()-1;i>=0;i--) ans += arr[i];
        while(ans.size()>1){
            if(ans[0]=='0') ans.pop_back();
            else break;
        }
        return ans;
    }
};