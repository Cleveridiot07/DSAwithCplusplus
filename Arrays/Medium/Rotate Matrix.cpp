#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

void printv(vector<int> v){
    for(int i:v) cout<<i<<" ";
    cout<<endl;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int index = 0;

        while (index < n / 2) {
            int i = 0;

            while (i < n - 1 - 2 * index) { 
                int temp1 = matrix[index + i][n - 1 - index];
                int temp2 = matrix[n - 1 - index][n - 1 - index - i];
                int temp3 = matrix[n - 1 - index - i][index];
                
                matrix[index + i][n - 1 - index] = matrix[index][index + i];
                matrix[n - 1 - index][n - 1 - index - i] = temp1;
                matrix[n - 1 - index - i][index] = temp2;
                matrix[index][index + i] = temp3;

                i++; 
            }

            index++; 
        }
    }
};
