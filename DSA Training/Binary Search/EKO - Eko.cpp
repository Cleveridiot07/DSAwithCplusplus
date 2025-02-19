// https://www.spoj.com/problems/EKO/
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

bool check(VT &arr,int cHeight,int Target){
    int sum = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] > cHeight) sum += arr[i] - cHeight;
    }
    return sum >= Target;
}

void clever() {
    int x,y;
    cin>>x>>y;
    VT arr(x);
    for(int i=0;i<x;i++) cin>>arr[i];
    
    int low = 0;
    int high = *max_element(arr.begin(),arr.end());
    
    int ans = 0;
    while(low<=high){
        int mid =  low + (high-low)/2;
        if(check(arr,mid,y)){
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
    int t;
    cin >> t;
    while (t--) {
       clever();  
    }
    return 0;
}
