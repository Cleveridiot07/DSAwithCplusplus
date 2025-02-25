class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";  // Empty tree

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
                result += "#,";  // Use "#" for null nodes
            }
        }

        // Remove trailing null markers
        while (!result.empty() && result.back() == ',' || result.back() == '#') {
            result.pop_back();
        }

        return result;
    }

    // Decodes a serialized string to a tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;  // Handle empty input

        stringstream ss(data);
        string value;
        getline(ss, value, ',');  
        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, value, ',') && value != "#") {
                node->left = new TreeNode(stoi(value));
                q.push(node->left);
            }

            if (getline(ss, value, ',') && value != "#") {
                node->right = new TreeNode(stoi(value));
                q.push(node->right);
            }
        }

        return root;
    }
};
