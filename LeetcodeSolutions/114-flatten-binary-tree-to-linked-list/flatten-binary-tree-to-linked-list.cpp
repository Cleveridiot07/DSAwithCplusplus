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
    TreeNode* helper(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->right = helper(root->left);
        TreeNode* temp = root;
        while(temp->right != nullptr) temp = temp->right;
        temp->right = helper(right);
        root->left = nullptr;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};