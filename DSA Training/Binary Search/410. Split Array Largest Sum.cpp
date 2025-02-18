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
    bool check(int currentSum, vector<int>& nums, int k) {
        int count = 1; 
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (sum > currentSum) {
                count++;
                sum = nums[i];
            }
            
            if (count > k) return false; 
        }
        
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int maxi = -1;
        

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }

        int low = maxi, high = sum;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (check(mid, nums, k)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
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