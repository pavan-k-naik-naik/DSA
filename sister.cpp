class Solution {
public:

    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& inorder,
                    vector<int>& postorder,
                    int left,
                    int right,
                    int &postIndex) {

        // No nodes
        if (left > right)
            return NULL;

        // Last element in postorder is root
        TreeNode* root = new TreeNode(postorder[postIndex]);

        postIndex--;

        // Position of root in inorder
        int mid = mp[root->val];

        // IMPORTANT:
        // Build right subtree first
        root->right = build(inorder,
                            postorder,
                            mid + 1,
                            right,
                            postIndex);

        // Then build left subtree
        root->left = build(inorder,
                           postorder,
                           left,
                           mid - 1,
                           postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int postIndex = postorder.size() - 1;

        return build(inorder,
                     postorder,
                     0,
                     inorder.size() - 1,
                     postIndex);
    }
};
