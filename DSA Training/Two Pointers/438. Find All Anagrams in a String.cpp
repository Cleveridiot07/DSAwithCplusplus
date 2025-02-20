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
        vector<int> findAnagrams(string s, string p) {
            vector<int> ans;
            int m = s.size();
            int n = p.size();
            if (m < n) return ans;
    
            vector<int> freqCountS(26, 0);
            vector<int> freqCountP(26, 0);
            int required = 0;
    
            for (int i = 0; i < n; i++) {
                freqCountP[p[i] - 'a']++;
                freqCountS[s[i] - 'a']++;
            }
    
            for (int i = 0; i < 26; i++) {
                if (freqCountS[i] != freqCountP[i]) required++;
            }
    
            int i = 0, j = n;
            while (j <= m) {
                if (required == 0) ans.push_back(i);
    
                if (freqCountS[s[i] - 'a'] == freqCountP[s[i] - 'a']) 
                    required++;
    
                freqCountS[s[i] - 'a']--;
    
                if (freqCountS[s[i] - 'a'] == freqCountP[s[i] - 'a']) 
                    required--;
    
                if (j < m) {
                    if (freqCountS[s[j] - 'a'] == freqCountP[s[j] - 'a']) 
                        required++;
    
                    freqCountS[s[j] - 'a']++;
    
                    if (freqCountS[s[j] - 'a'] == freqCountP[s[j] - 'a']) 
                        required--;
                }
    
                i++;
                j++;
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