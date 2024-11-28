#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to merge k sorted arrays
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // Min-heap to store (value, array index, element index)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Insert the first element of each array into the heap
        for (int i = 0; i < K; i++) {
            if (!arr[i].empty()) {
                pq.push({arr[i][0], i, 0});
            }
        }

        vector<int> result;

        // Process the heap
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int value = current[0];      // The value of the element
            int arrayIndex = current[1]; // Index of the array
            int elementIndex = current[2]; // Index of the element in the array

            // Add the smallest value to the result
            result.push_back(value);

            // If there are more elements in the current array, push the next element
            if (elementIndex + 1 < arr[arrayIndex].size()) {
                pq.push({arr[arrayIndex][elementIndex + 1], arrayIndex, elementIndex + 1});
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int K = 3;

    vector<int> mergedArray = sol.mergeKArrays(arr, K);

    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
