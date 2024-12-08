#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        
        vector <string> zigzag(numRows);
        int i=0;
        int row = 0;
        bool direction = 1;
        string ans = "";
        
        if(numRows == 1)
            return s;
        
      while(true){
          if(direction){
              while(row < numRows && i<s.size()){
                  zigzag[row++].push_back(s[i++]);
              }
              row = numRows-2;
          }
          else{
              while(row>=0 && i<s.size()){
                  zigzag[row--].push_back(s[i++]);
              }
              row=1;
          }

          if(i>=s.size()) break;
          direction = !direction;
      }     
        
        for(int i=0;i<zigzag.size();i++){
            ans = ans + zigzag[i];
        }
        
        return ans;
    }
};