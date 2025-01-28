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

// Approach O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        if( n == 0 ) return {0};
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        int currentPower = 1;
        int index = 0;
        for(int i=2;i<=n;i++){
            if(i == pow(2,currentPower+1)){
                index = 0;
                currentPower++;
            }
            ans[i] = 1 + ans[index];
            index++;
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