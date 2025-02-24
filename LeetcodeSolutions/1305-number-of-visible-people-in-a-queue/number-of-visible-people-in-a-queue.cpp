class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);  
        stack<int> stk; 

        for(int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] <= heights[i]) {
                stk.pop();
                result[i]++; 
            }
            
            if (!stk.empty()) {
                result[i]++; 
            }
            stk.push(i);
        }
        
        return result;
    }
};
