class Solution {
    public int climbStairs(int n) {
        return climbStairsHelper(n, new int[n + 1]);
    }

    private int climbStairsHelper(int n, int[] memo) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        if (memo[n] != 0) return memo[n];

        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        return memo[n];
    }
}
