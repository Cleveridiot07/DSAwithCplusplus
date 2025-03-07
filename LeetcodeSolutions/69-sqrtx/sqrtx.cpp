class Solution {
public:
    int mySqrt(int x) {
        int s = 0 , e = x;
        int sqr = 0;
        while( s <= e){
            long long int mid = s + (e-s)/2;
            if(mid*mid*1L == x) return mid;
            else if(mid*mid < x){
                sqr = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return sqr;
    }
};