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

class Solution {
    int helper(vector<int>& coins, int amount,long int prevAmount,int count,int index){
        if(prevAmount > amount || index >= coins.size()) return -1;
        if(prevAmount == amount) return count;

        // not take
        int way1 = helper(coins,amount,prevAmount,count,index+1);
        // take
        prevAmount += coins[index];
        int way2 = helper(coins,amount,prevAmount,count+1,index);

        if(way1 != -1 && way2 != -1) return min(way1,way2);
        if(way1 == -1 && way2 == -1) return -1;
        return way1 == -1 ? way2 : way1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return helper(coins,amount,0,0,0);
    }
};

// Memoization
class Solution {
    int helper(vector<int>& coins, int amount, int index,vector<vector<int>> &dp) {
        if (amount == 0) return 0; 
        if (index < 0 || amount < 0) return INT_MAX; 

        if(dp[index][amount] != -1) return dp[index][amount];

        int notTake = helper(coins, amount, index - 1,dp);

        int take = INT_MAX;
        if (coins[index] <= amount) {
            int res = helper(coins, amount - coins[index], index,dp); 
            if (res != INT_MAX) take = 1 + res; 
        }

        return dp[index][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int result = helper(coins, amount, coins.size() - 1,dp);
        return (result == INT_MAX) ? -1 : result; 
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