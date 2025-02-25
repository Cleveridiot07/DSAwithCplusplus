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
    int helper(TreeNode* root, int preDigit) {
        if (!root) return 0;  
        preDigit = preDigit * 10 + root->val; 
        if (!root->left && !root->right) return preDigit;
        return helper(root->left, preDigit) + helper(root->right, preDigit);
    }

public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};
