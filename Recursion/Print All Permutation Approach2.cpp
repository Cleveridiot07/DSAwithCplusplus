#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;
void helper(vector<vector<int>> &output,vector<int> &pre,int index,vector<int> &arr){
    if(pre.size()>= arr.size()){
        output.push_back(pre);
        return;
    }

    for(int i=index;i<arr.size();i++){
            pre.push_back(arr[i]);
            swap(arr[index],arr[i]);
            
            helper(output,pre,index+1,arr);

            pre.pop_back();
            swap(arr[index],arr[i]);
    }

}

// Time Complexity : O(n!*n)
// Space Complexity : O(n) no* visited array, recursion stack + Output 2D array (n!*n); 

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    sort(arr.begin(),arr.end());

    vector<vector<int>> output;
    vector<bool> visited(n,false);
    vector<int> pre;


    helper(output,pre,0,arr);

    for(auto arr: output){
        for(int i: arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }


    return 0;
}