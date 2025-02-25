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