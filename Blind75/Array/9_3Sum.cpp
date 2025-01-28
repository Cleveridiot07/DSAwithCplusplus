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

// Approach 1 O(n3)

class Solution {
    int binarySearch(int s,int e,vector<int> &nums,int target){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) e=mid-1;
            else s= mid+1;
        }
        return -1;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        int i = 0; 
        while(i<nums.size()-2){
            int j = nums.size()-1;
            while(i<j-1){
                int sum = nums[i]+nums[j];
                int index = binarySearch(i+1,j-1,nums,0-sum);
                if(index !=-1) ans.insert({nums[i],nums[index],nums[j]});
                j--;
            }
            i++;
        }
        vector<vector<int>> answer(ans.begin(), ans.end());
        return answer;
    }
};

// Approach O(n2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0, j, k;

        while (i < nums.size()) {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
            i++;
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