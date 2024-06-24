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
    private:
    int height(TreeNode*root,int &maxi)
    {
        if(root==NULL) return 0;
        int data=root->val;
        
      
        int lh=max(0,height(root->left,maxi));
        int rh=max(0,height(root->right,maxi));
         maxi=max(maxi,root->val+lh+rh);
        return max(lh,rh)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        
        height(root,maxi);

        return maxi;
        
    }
};