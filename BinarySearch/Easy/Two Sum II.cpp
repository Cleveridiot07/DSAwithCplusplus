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
    int binarysearch(vector<int> &numbers, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (numbers[mid] == target) return mid;
            else if (numbers[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1; // Return -1 if the target is not found
    }

public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int ft = target - numbers[i]; // Calculate the complementary value
            int index = binarysearch(numbers, i + 1, numbers.size() - 1, ft); // Only search forward
            if (index != -1) {
                return {i + 1, index + 1}; // Return the 1-based indices
            }
        }
        return {}; // Return an empty vector if no solution is found
    }
};
