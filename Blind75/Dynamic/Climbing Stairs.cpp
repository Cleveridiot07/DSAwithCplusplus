#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
#include <stack>
#include <set>
using namespace std;

// Typedefs
typedef long long ll;
typedef double db;
typedef unsigned int ui;
typedef vector<ll> VT;
typedef pair<int, int> pii;

// Macros
#define sz(x) ((int)((x).size()))
#define max_val(a, b) (a < b ? b : a)
#define min_val(a, b) (a < b ? a : b)
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second

template <typename T>
void printVector(vector<T> &arr) {
    for (int i = 0; i < sz(arr); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Recursion
// Time complexity =  O(2^n)
// Space Complexity =  O(n) for recursion stack
class Solution {
    int helper(int n){
        if (n<=1) return 1;
        return helper(n-1)+helper(n-2);
    }
public:
    int climbStairs(int n) {
        return helper(n);
    }
};


// Memoization
// Time complexity =  O(n)
// Space Complexity =  O(n) for recursion stack + O(n) for dp  Array
class Solution {
    int helper(int n,vector<int> &dp){
        if (n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n-1,dp)+helper(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};

// Tabulation
// Time complexity =  O(n)
// Space Complexity = O(n) for dp  Array
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Optimal Solution
// Time complexity =  O(n)
// Space Complexity = O(1) 
class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 = 1;
        for(int i=2;i<=n;i++){
            int current = prev1+prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

void clever() {
    // write your code here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        clever();
    }
    return 0;
}