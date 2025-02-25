class Solution {
    int diameter(TreeNode* root, int &maxD) {
        if (root == nullptr) return 0;
        int left = diameter(root->left,maxD);
        int right = diameter(root->right,maxD);

        maxD= max(maxD,left+right);
        return max(left,right)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        diameter(root,maxD);
        return maxD;

    }
};