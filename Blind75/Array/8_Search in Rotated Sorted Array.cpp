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

// Approach 1 O(LogN)

class Solution {
    int returnPivot(vector<int>& nums){
        int s = 0;
        int e = nums.size()-1;
        int minIndex = 0;
        while(s<=e){
            int mid  = s+(e-s)/2;
            if(nums[mid]<nums[minIndex]) minIndex = mid;
            if(nums[e]<nums[mid]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }

        return minIndex;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = returnPivot(nums);
        int s = 0;
        int e = nums.size()-1;
        if(nums[pivot]<=target && nums[e]>=target){
            while(pivot<=e){
                int mid = pivot+(e-pivot)/2;
                if(nums[mid]== target) return mid;
                else if(nums[mid]>target) e = mid-1;
                else pivot = mid+1;
            }
        }else{
            while(s<=pivot){
                int mid = s+(pivot-s)/2;
                if(nums[mid]== target) return mid;
                else if(nums[mid]>target) pivot = mid-1;
                else s = mid+1;
            }

        }

        return -1;
        
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