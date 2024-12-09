#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;


// Time Complexity = O(n) for finding dip + O(n) for finding slighlty greator element + O(nlogn) for sorting
// Space Complexity = O(n)

void printv(vector<int> v){
    for(int i:v) cout<<i<<" ";
    cout<<endl;
}

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
        int slighltyGreator = arr[index+1];
        int slightlyGreatorindex = index+1;
        for(int temp = index;temp<n;temp++){
            if(arr[temp]>arr[index]  && slighltyGreator>arr[index]){
                slightlyGreatorindex = temp;
            }
        }
        swap(arr[index],arr[slightlyGreatorindex]);
        sort(arr.begin()+index,arr.end());
    }

    printv(arr);


    return 0;
}