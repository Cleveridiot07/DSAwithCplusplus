class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> left(n,-1);
        vector<int> right(n,n);
        

        for(int i = 0; i < n;i++){
            while(st.size() > 0 && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        for(int i = n-1; i >= 0;i--){
            while(st.size() > 0 && arr[st.top()]> arr[i]) st.pop();
            if(!st.empty()){
                 right[i] = st.top();
            }
            st.push(i);
        }


        int maxArea = 0;
        for(int i=0;i<n;i++){
            int cArea = arr[i] * (right[i] - left[i] - 1);
            maxArea = max(cArea,maxArea);
        }
        

        return maxArea;
    }
};