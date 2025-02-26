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
    int helper(TreeNode* node,int &maxPath){
        if(node == nullptr) return 0;
        int leftPath = helper(node->left,maxPath);
        int rightPath = helper(node->right,maxPath);

        int way1 = leftPath + node->val;
        int way2 = rightPath + node->val;
        int way3 = leftPath+rightPath + node->val;
        maxPath = max(maxPath,max(way1,max(way2,max(way3,node->val))));

        int ret  = max(leftPath,rightPath);
        return ret>0 ? node->val+ret : node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        helper(root,maxPath);
        return maxPath;
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