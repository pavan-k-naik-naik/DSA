class Solution {
public:
 int ans=INT_MIN;
 int solve(TreeNode*root)
   {if(root==NULL)
      return 0;
      int left=solve(root->left);
      int right=solve(root->right);
       left=max(0,left);
       right=max(0,right);
       ans=max(ans,left+right+root->val);
         return root->val+max(left,right);}





    int maxPathSum(TreeNode* root) {

        solve(root);
         return ans;
         
        
    }
};
