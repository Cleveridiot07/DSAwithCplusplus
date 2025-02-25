class Solution {
    pair<int, int> diameter(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = diameter(root->left);
        auto right = diameter(root->right);

        int height = max(left.first, right.first) + 1;
        int maxDiameter = max({left.second, right.second, left.first + right.first});

        return {height, maxDiameter};
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).second;
    }
};
