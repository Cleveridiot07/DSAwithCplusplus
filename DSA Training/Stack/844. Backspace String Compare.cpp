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
        bool backspaceCompare(string s, string t) {
            int skip1 = 0, skip2 = 0;
            int i = s.size() - 1, j = t.size() - 1;
    
            while (i >= 0 || j >= 0) {
    
                while (i >= 0) {
                    if (s[i] == '#') {
                        skip1++, i--;
                    } else if (skip1 > 0) {
                        skip1--, i--;
                    } else {
                        break;
                    }
                }
    
       
                while (j >= 0) {
                    if (t[j] == '#') {
                        skip2++, j--;
                    } else if (skip2 > 0) {
                        skip2--, j--;
                    } else {
                        break;
                    }
                }
    
                if (i >= 0 && j >= 0 && s[i] != t[j]) {
                    return false;
                }
    
                if ((i >= 0) != (j >= 0)) {
                    return false;
                }
    
                i--, j--;
            }
    
            return true;
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