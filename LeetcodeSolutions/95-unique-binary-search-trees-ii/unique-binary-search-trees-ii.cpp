class Solution {
    vector<TreeNode*> helper(int l, int r) {
        if (l > r) return {nullptr};  

        vector<TreeNode*> trees;

        for (int i = l; i <= r; i++) { 
            vector<TreeNode*> leftTrees = helper(l, i - 1);  
            vector<TreeNode*> rightTrees = helper(i + 1, r); 

    
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i); 
                    root->left = left;
                    root->right = right;
                    trees.push_back(root); 
                }
            }
        }
        return trees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }
};
