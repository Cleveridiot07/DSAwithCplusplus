#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;
void helper(vector<vector<int>> &output,vector<int> &pre,vector<bool> visited,vector<int> &arr){
    if(pre.size()>= arr.size()){
        output.push_back(pre);
        return;
    }

    for(int i=0;i<arr.size();i++){
        if(!visited[i]){
            pre.push_back(arr[i]);
            visited[i] = true;
            helper(output,pre,visited,arr);

            pre.pop_back();
            visited[i] = false;
        }
    }

}

// Time Complexity : O(n!*n)
// Space Complexity : O(n) +  O(n) visited array, recursion stack + Output 2D array (n!*n); 


int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    sort(arr.begin(),arr.end());

    vector<vector<int>> output;
    vector<bool> visited(n,false);
    vector<int> pre;


    helper(output,pre,visited,arr);

    for(auto arr: output){
        for(int i: arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }


    return 0;
}