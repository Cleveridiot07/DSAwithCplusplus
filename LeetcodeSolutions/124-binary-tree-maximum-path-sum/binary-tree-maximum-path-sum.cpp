class Solution {
    int helper(TreeNode* node,int &maxPath){
        if(node == nullptr) return 0;
        int leftPath = helper(node->left,maxPath);
        int rightPath = helper(node->right,maxPath);

        maxPath = max(maxPath,leftPath + node->val);
        maxPath = max(maxPath,rightPath + node->val);
        maxPath = max(maxPath,rightPath+leftPath + node->val);
        maxPath = max(maxPath,node->val);

        if(leftPath <= 0 && rightPath <= 0) return node->val;

        return max(leftPath,rightPath) + node->val;
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        helper(root,maxPath);
        return maxPath;
    }
};