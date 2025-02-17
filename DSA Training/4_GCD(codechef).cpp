#include <bits/stdc++.h>
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
    
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];
    
    int l,r;
    cin>>l>>r;
    
    
    vector<int> prefixGCD(n);
    vector<int> suffixGCD(n);
    
    prefixGCD[0] = arr[0];
    
    for(int i=1;i<n;i++){
        prefixGCD[i] = __gcd(arr[i],prefixGCD[i-1]);
    }
    
    suffixGCD[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffixGCD[i] = __gcd(arr[i],suffixGCD[i+1]);
    }
    
    
    int result = 0;
    if (l > 0) result = prefixGCD[l - 1]; 
    if (r < n - 1) result = __gcd(result, suffixGCD[r + 1]);
    
    
    cout<< result<<endl;
    
    
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
