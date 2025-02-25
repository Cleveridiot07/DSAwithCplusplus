class Solution {
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
