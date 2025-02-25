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
    // int preIndex = 0;
    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder,int s,int e){
        if(s>e) return nullptr;
        
        int val = preorder[0];
        TreeNode* root = new TreeNode(val);

        int inIndex = s;
        while(inIndex <= e && inorder[inIndex] != val){
            inIndex++;
        }

        preorder.erase(preorder.begin());


        root->left = treeBuilder(preorder,inorder,s,inIndex - 1);
        root->right = treeBuilder(preorder,inorder,inIndex+1,e);


        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return treeBuilder(preorder,inorder,0,preorder.size()-1);
    }
};