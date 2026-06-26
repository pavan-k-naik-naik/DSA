class Solution {
public:

    // Store parent of every node
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // child -> parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;

        markParents(root, parent);

        // BFS Queue
        queue<TreeNode*> q;

        // Visited nodes
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int distance = 0;

        while (!q.empty()) {

            int size = q.size();

            // If we reached distance k,
            // all nodes in queue are the answer.
            if (distance == k)
                break;

            distance++;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Visit left child
                if (node->left && !visited[node->left]) {

                    visited[node->left] = true;
                    q.push(node->left);
                }

                // Visit right child
                if (node->right && !visited[node->right]) {

                    visited[node->right] = true;
                    q.push(node->right);
                }

                // Visit parent
                if (parent[node] && !visited[parent[node]]) {

                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {

            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
