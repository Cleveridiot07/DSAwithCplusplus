// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A

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

void clever() {
    int x,y;
    cin>>x>>y;
    VT arr(x);
    for(int i=0;i<x;i++) cin>>arr[i];
    int i = 0, j = 0;
    int sum = 0;
    int maxLength = 0;
    while(i<=j && j<x){
        if(sum < y){
            maxLength = max(maxLength,j-i);
            sum += arr[j];
            j++;
        }else{
            if(sum == y){
                maxLength = max(maxLength,j-i);
            }
            sum -= arr[i];
            i++;
        }
    }
    
    cout<<maxLength<<endl;
    
    
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
