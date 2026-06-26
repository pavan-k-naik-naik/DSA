class Solution {
public:

    // Find the height by going only to the left
    int leftHeight(TreeNode* root) {

        int height = 0;

        while (root) {
            height++;
            root = root->left;
        }

        return height;
    }

    // Find the height by going only to the right
    int rightHeight(TreeNode* root) {

        int height = 0;

        while (root) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {

        if (root == NULL)
            return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // Perfect Binary Tree
        if (lh == rh)
            return (1 << lh) - 1;

        // Otherwise recurse
        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};
