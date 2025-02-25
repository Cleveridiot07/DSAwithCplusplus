
class Solution {
    void helper(TreeNode* root,vector<int> &output){
        if(root == nullptr) return;
        output.push_back(root->val);
        helper(root->left,output);
        helper(root->right,output);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};