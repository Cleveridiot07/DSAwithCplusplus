class Codec {
public:

 
    string serialize(TreeNode* root) {
        if (!root) return "#,"; 
        
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string value;

        while (getline(ss, value, ',')) {
            nodes.push(value);
        }

        return buildTree(nodes);
    }

private:
    TreeNode* buildTree(queue<string>& nodes) {
        if (nodes.empty()) return nullptr;

        string value = nodes.front();
        nodes.pop();

        if (value == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(value));
        root->left = buildTree(nodes);
        root->right = buildTree(nodes);

        return root;
    }
};
