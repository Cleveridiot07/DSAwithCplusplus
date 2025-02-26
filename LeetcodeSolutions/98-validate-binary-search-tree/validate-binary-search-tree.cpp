
class Solution {
private:
    bool helper(TreeNode* root,long  lRange,long  RRange){
        if (!root) return true;
        if(!(root->val > lRange && root->val<RRange)) return false;
        return helper(root->left,lRange,root->val) && helper(root->right,root->val,RRange);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,(1L*INT_MIN)-1,(1L*INT_MAX)+1);
    }
};   