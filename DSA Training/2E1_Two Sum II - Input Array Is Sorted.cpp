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

// O(n);

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
           int i = 0, j = numbers.size()-1;
           while(i<j){
            if(numbers[i] + numbers[j] == target) return {i+1,j+1};
            else if (numbers[i] + numbers[j] > target) j--;
            else i++;
           }
            return {-1,-1};
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