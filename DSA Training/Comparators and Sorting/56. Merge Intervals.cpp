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
    static bool comparator(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);
        vector<vector<int>> ans(intervals.begin(), intervals.end());
        int i = 1;
        while(i<ans.size() && ans.size()>1){
            if(ans[i-1][1] >= ans[i][0] && ans[i-1][1] < ans[i][1]){
                int a = ans[i-1][0];
                int b = ans[i][1];
                ans.erase(ans.begin()+i-1);
                ans.erase(ans.begin()+i-1);
                ans.insert(ans.begin()+i-1,{a,b});
                i--;
            }else if(ans[i-1][1] >= ans[i][0] && ans[i-1][1] >= ans[i][1]){
                ans.erase(ans.begin()+i);
                i--;
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