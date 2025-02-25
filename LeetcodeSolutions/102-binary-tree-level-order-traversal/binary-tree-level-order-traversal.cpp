class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> ans;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
                int s = qt.size();
                vector<int> tempArr;
                for(int i=0;i<s;i++){
                    TreeNode* temp = qt.front();
                    qt.pop();
                    tempArr.push_back(temp->val);
                    if(temp->left != nullptr) qt.push(temp->left);
                    if(temp->right != nullptr) qt.push(temp->right);
                }
                ans.push_back(tempArr);
        }

        return ans;
    }
};