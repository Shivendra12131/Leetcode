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
    bool preorder(TreeNode*lef,TreeNode*rigt)
    {
        if(lef==NULL||rigt==NULL) return lef==rigt;
        if(lef->val!=rigt->val) return false;
        return preorder(lef->left,rigt->right)
        &&preorder(lef->right,rigt->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return preorder(root->left,root->right);
        
        
    }
};