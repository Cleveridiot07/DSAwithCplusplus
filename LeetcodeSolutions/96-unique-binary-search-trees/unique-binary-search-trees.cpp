class Solution {
    int numberOfWays(int n){
        if(n == 0 || n == 1) return 1;  

        int number = 0;
        for(int i = 1; i <= n; i++){
            int left = numberOfWays(i - 1);  
            int right = numberOfWays(n - i); 

            number += (left * right); 
        }

        return number;
    }
public:
    int numTrees(int n) {
        return numberOfWays(n);
    }
};