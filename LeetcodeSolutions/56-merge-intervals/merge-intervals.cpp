class Solution {
    static bool comparator(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        vector<vector<int>> ans(intervals.begin(), intervals.end());
        int i = 1;
        while(i<ans.size() && ans.size()>1){
            if(ans[i-1][1] >= ans[i][0] && ans[i-1][1] < ans[i][1]){
                int a = ans[i-1][0];
                int b = ans[i][1];
                ans.erase(ans.begin()+i-1);
                ans.erase(ans.begin()+i-1);
                ans.insert(ans.begin()+i-1,{a,b});
                i--;
            }else if(ans[i-1][1] >= ans[i][0] && ans[i-1][1] >= ans[i][1]){
                ans.erase(ans.begin()+i);
                i--;
            }
            i++;
        }

        return ans;
    }
};