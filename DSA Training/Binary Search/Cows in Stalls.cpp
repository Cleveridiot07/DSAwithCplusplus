// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/C
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

bool check(VT &arr, int cows, int diff) {
    int placedCows = 1;  
    int lastPlaced = arr[0];  

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - lastPlaced >= diff) {
            placedCows++;
            lastPlaced = arr[i];
        }
        if (placedCows >= cows) return true;  
    }
    return false;
}


void clever() {
    int x,y;
    cin>>x>>y;
    VT arr(x);
    for(int i=0;i<x;i++) cin>>arr[i];
    
    int low = 0;
    int high = arr[x-1];
    int ans = 0;
    while(low<=high){
        int mid =  low + (high-low)/2;
        if(check(arr,y,mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    cout<<ans<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
       clever();  
    }
    return 0;
}
