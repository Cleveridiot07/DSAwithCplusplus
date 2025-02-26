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


#include <queue>
#include <vector>
using namespace std;

class Solution1 {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            multiset<int> ms;
            vector<int> ans;
            for(int i=0;i<nums.size();i++){
                ms.insert(nums[i]);
                if(i >= k-1){
                    ans.push_back(*ms.rbegin());
                    std::multiset<int>::iterator it = ms.find(nums[i-k+1]);
                    ms.erase(it);
                }
            }
    
            return ans;
        }
    };

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; 
        vector<int> result;
        
        for (int j = 0; j < nums.size(); j++) {
            pq.push({nums[j], j});
            if (j >= k - 1) {
                while (pq.top().second <= j - k) {
                    pq.pop();
                }
                result.push_back(pq.top().first);
            }
        }
        
        return result;
    }
};



class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq;
            vector<int> result;
    
            for (int i = 0; i < nums.size(); ++i) {
                if (!dq.empty() && dq.front() < i - k + 1) {
                    dq.pop_front();
                }
    
                while (!dq.empty() && nums[dq.back()] < nums[i]) {
                    dq.pop_back();
                }
    
                dq.push_back(i);
    
                if (i >= k - 1) {
                    result.push_back(nums[dq.front()]);
                }
            }
    
            return result;
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