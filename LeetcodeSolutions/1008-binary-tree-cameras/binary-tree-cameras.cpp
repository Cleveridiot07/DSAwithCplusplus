class Solution {
    int helper(TreeNode* root, int &count) {
        if (!root) return 2;  

        int left = helper(root->left, count);
        int right = helper(root->right, count);

        if (left == 0 || right == 0) {  
            count++;
            return 1; 
        }

        if (left == 1 || right == 1) {  
            return 2;
        }

        return 0;  
    }

public:
    int minCameraCover(TreeNode* root) {
        int count = 0;
        if (helper(root, count) == 0) count++; 
        return count;
    }
};
