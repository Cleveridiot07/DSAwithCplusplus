class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "#";  

        queue<TreeNode*> q;
        q.push(root);
        string result;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "#,";
            }
        }

        result.pop_back(); 
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;

        stringstream ss(data);
        string value;
        vector<TreeNode*> nodes;

        while (getline(ss, value, ',')) {
            if (value == "#") {
                nodes.push_back(nullptr);
            } else {
                nodes.push_back(new TreeNode(stoi(value)));
            }
        }

        int index = 1;
        for (int i = 0; i < nodes.size(); i++) {
            if (!nodes[i]) continue;

            if (index < nodes.size()) nodes[i]->left = nodes[index++];
            if (index < nodes.size()) nodes[i]->right = nodes[index++];
        }

        return nodes[0];
    }
};
