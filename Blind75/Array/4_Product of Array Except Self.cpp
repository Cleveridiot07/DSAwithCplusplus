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

// Approach Time Complexity = O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int CountZero = 0;
        int CalcM = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                CalcM *= nums[i];
            }else{
                CountZero++;
            }
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(CountZero > 1) ans[i] = 0;
            else if(CountZero == 1){
                if(nums[i] == 0) ans[i] = CalcM;
                else ans[i] = 0;
            }
            else{
                ans[i] = CalcM/nums[i]; 
            }
        }
        return ans;
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