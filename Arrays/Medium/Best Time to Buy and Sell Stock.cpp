#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int minimumPrice = prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i] > minimumPrice){
                maxi = max(prices[i]-minimumPrice,maxi);
            }else{
                minimumPrice = prices[i];
            } 
        }

        return maxi;
        
    }
};