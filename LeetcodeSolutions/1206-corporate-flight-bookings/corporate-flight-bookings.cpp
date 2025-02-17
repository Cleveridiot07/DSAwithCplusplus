class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for(auto it: bookings){
            int left = it[0] - 1;
            int right = it[1];
            ans[left] += it[2];
            if(right < n) ans[right] -= it[2]; 
        }
        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};