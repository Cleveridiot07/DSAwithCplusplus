class Solution {
public:
    long numOfSubarrays(vector<int>& arr) {
        long ans=0;
        int even=0,odd=0,sum=0;
        int size=arr.size();
        for(int i=0;i<size;i++){
            sum=sum+arr[i];
            if(sum%2==0){
                ans=ans+odd;
                even=even+1;
            }
            else{
                ans=ans+even+1;
                odd=odd+1;
            }
        }
        return ans%1000000007;
    }
};