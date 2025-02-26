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
 

// Approach 1  Recursive
class Solution1 {
    void traverse(vector<int> &arr,TreeNode* root){
        if(root == nullptr) return;
        arr.push_back(root->val);
        traverse(arr,root->left);
        traverse(arr,root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(ans,root);
        return ans;
    }
};

// Approach 2  Iterative
class Solution2 {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            if(root==nullptr) return{};
            vector<int> ans;
            stack<TreeNode*> st;
            st.push(root);
            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                ans.push_back(node->val);
                if(node->right != nullptr) st.push(node->right);
                if(node->left != nullptr) st.push(node->left);
    
            }
            return ans;
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