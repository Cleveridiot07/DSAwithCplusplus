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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int preIndex = 0;
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder,int s,int e){
        if(s>e) return nullptr;
        
        int val = preorder[preIndex++];
        TreeNode* root = new TreeNode(val);

        int inIndex = s;
        while(inIndex <= e && inorder[inIndex] != val){
            inIndex++;
        }

        root->left = treeBuilder(preorder,inorder,s,inIndex - 1);
        root->right = treeBuilder(preorder,inorder,inIndex+1,e);


        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return treeBuilder(preorder,inorder,0,preorder.size()-1);
    }
};



class Solution2 {
    int preIndex = 0;
    unordered_map<int, int> inMap;

    TreeNode* treeBuilder(vector<int>& preorder, int s, int e) {
        if (s > e) return nullptr;

        int val = preorder[preIndex++];
        TreeNode* root = new TreeNode(val);

        int inIndex = inMap[val];

        root->left = treeBuilder(preorder, s, inIndex - 1);
        root->right = treeBuilder(preorder, inIndex + 1, e);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return treeBuilder(preorder, 0, inorder.size() - 1);
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