#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;


// Time Complexity
// Space Complexity

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];


    int index;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1) sort(arr.begin(),arr.end());
    else{
        
    }



    return 0;
}