#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
#include <stack>
#include <set>
using namespace std;

// Typedefs
typedef long long ll;
typedef double db;
typedef unsigned int ui;
typedef vector<ll> VT;
typedef pair<int, int> pii;

// Macros
#define sz(x) ((int)((x).size()))
#define max_val(a, b) (a < b ? b : a)
#define min_val(a, b) (a < b ? a : b)
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second

template <typename T>
void printVector(vector<T> &arr) {
    for (int i = 0; i < sz(arr); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
    int diameter(TreeNode* root, int &maxD) {
        if (root == nullptr) return 0;

        int left = diameter(root->left, maxD);
        int right = diameter(root->right, maxD);
        
        maxD = max(maxD, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        diameter(root, maxD);
        return maxD;
    }
};

// Without ref variable
class Solution {
    pair<int, int> diameter(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = diameter(root->left);
        auto right = diameter(root->right);

        int height = max(left.first, right.first) + 1;
        int maxDiameter = max({left.second, right.second, left.first + right.first});

        return {height, maxDiameter};
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).second;
    }
};


void clever() {
    // write your code here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        clever();
    }
    return 0;
}