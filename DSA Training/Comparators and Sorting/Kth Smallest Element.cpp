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

class Solution{
    // Approach 1
    public:
    int kthSmallest(vector<int> &nums, int k) {
        priority_queue<int,vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        for (int i = 1; i < k; i++) {
            minHeap.pop();
        }
        return minHeap.top();
    }
    
    

};

class Solution2{
    // Approach 2 using quick select 
    // Time complexity (Average): O(n)
    // Worst Case: O(n^2)
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    int quickSelect(vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pi = partition(arr, low, high);

            if (pi == k - 1) {
                return arr[pi];
            }

            if (pi > k - 1) quickSelect(arr, low, pi - 1, k);
            else quickSelect(arr, pi + 1, high, k);
        }else{
            return -1;
        }
    }

public:
    int kthSmallest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
        
    }
};



class Solution3 {
    // Approach 3 
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int min = *min_element(nums.begin(), nums.end());
            int max = *max_element(nums.begin(), nums.end());
    
            vector<int> count(max-min+1, 0);
            for (auto n : nums) {
                count[n-min]++;
            }
            int c = 0;
            int res = 0;
            for (int i=max; i >= min; --i) {
                if (count[i-min]) {
                    c += count[i-min];
                    if (c >= k) {
                        res = i;
                        break;
                    }
                }
            }
            return res;
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