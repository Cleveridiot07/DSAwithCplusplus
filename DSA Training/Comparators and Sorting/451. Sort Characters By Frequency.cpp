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
    static bool comparator(pair<char, int> a,pair<char, int> b){
        return a.second>b.second;
    }
public:
    string frequencySort(string s) {
        vector<pair<char, int>> characters(62, {'#', 0});
        for (char ch : s) {
            if ('a' <= ch && ch <= 'z') {
                characters[ch - 'a'] = {ch, characters[ch - 'a'].second + 1};
            } else if ('A' <= ch && ch <= 'Z') {
                characters[26 + (ch - 'A')] = {ch, characters[26 + (ch - 'A')].second + 1};
            }else{
                characters[52 + (ch - '0')] = {ch, characters[52 + (ch - '0')].second + 1};
            }
        }

        sort(characters.begin(), characters.end(), Solution::comparator);
        string ans = "";
        for(int i=0;i<62;i++){
            if(characters[i].second>0){
                string currentString = "";
                int n = characters[i].second;
                while(n--) currentString += characters[i].first;
                ans += currentString;
            }
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