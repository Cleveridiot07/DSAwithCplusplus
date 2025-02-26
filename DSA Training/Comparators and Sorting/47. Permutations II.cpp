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
    public:
        void helper(vector<int> num, int i, int j, vector<vector<int> > &output) {
            if (i == j-1) {
                output.push_back(num);
                return;
            }
            for (int k = i; k < j; k++) {
                if (i != k && num[i] == num[k]) continue;
                swap(num[i], num[k]);
                helper(num, i+1, j, output);
            }
        }
        vector<vector<int> > permuteUnique(vector<int> &num) {
            sort(num.begin(), num.end());
            vector<vector<int> >output;
            helper(num, 0, num.size(), output);
            return output;
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