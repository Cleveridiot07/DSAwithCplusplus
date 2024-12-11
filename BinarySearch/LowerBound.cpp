#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

    int findFloor(vector<int>& arr, int k) {
        int s = 0, e = arr.size()-1;
        int flr = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid] <= k){
                flr = mid;
                s = mid+1; 
            }else{
                e=mid-1;
            }
        }
        
        return flr;
        
    }