#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

// Liner Traversal will be more efficirnt as the TC here in O(nlogn) for sorting





    vector<int> getFloorAndCeil(int k, vector<int> &arr) {
        int s = 0, e = arr.size()-1;
        int flr = -1;
        int cil = -1;
        sort(arr.begin(),arr.end());
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid] == k) {
                flr = arr[mid];
                cil = arr[mid];
                break;
            }
            if(arr[mid] < k){
                flr = arr[mid];
                s = mid+1; 
            }else{
                cil = arr[mid];
                e=mid-1;
            }
        }
        
        return {flr,cil};
    }