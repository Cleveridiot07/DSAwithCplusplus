#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to replace each element with its rank in the sorted array.
    vector<int> replaceWithRank(vector<int>& arr) {
        vector<int> demo(arr.begin(), arr.end());
        sort(demo.begin(), demo.end());  // O(N log N) - Sorting the array
        
        map<int, int> mp;  // O(N) - Map to store ranks of unique elements
        int rank = 1;
        int prev = demo[0];

        // O(N) - Assign ranks to elements, handling duplicates
        for (int i : demo) {
            if (i > prev) {
                rank++;
                mp[i] = rank;
                prev = i;
            } else {
                mp[i] = rank;
            }
        }

        vector<int> ans(arr.size());  // O(N) - Vector to store final ranks
        // O(N) - Construct the result array with ranks corresponding to the original array
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = mp[arr[i]];  // Replace element with its rank
        }

        return ans;  // Return the transformed array with ranks
    }
};

