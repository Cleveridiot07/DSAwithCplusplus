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
    bool helper(vector<int>& nums, int target,int s,int e){
        if(s>e) return false;
        int mid = s + (e-s)/2;
        if(nums[mid]==target) return true;
        if(nums[s] == nums[mid] && nums[mid] == nums[e]){
            return helper(nums,target,s,mid-1) || helper(nums,target,mid+1,e);
        }
        // Less than or Equals to condition is important to check for sorted array only for two elements*
        if(nums[s] <= nums[mid]){
            if(nums[s] <= target && nums[mid] > target) return helper(nums,target,s,mid-1);
            else return helper(nums,target,mid+1,e);
        }else{
            if(nums[mid] < target && nums[e] >= target) return helper(nums,target,mid+1,e);
            else return helper(nums,target,s,mid-1);
        }

        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        return helper(nums,target,0,nums.size()-1);
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