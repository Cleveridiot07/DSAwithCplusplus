class Solution {
    long long helper(long long n){
        if(n <= 1) return n;
        else return (n-1)*4 + helper(n-1);
    }
public:
    long long coloredCells(int n) {
        return helper(n);
    }
};