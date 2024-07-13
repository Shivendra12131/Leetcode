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
    int height(TreeNode*node){
        if(node==NULL) return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        // maxi=max(maxi,(lh+rh));
        return 1+max(lh,rh);

    }
public:
    int maxi=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        // int maxi=0;
        // height(root,maxi);
        // return maxi;
        // return 
        int lh=height(root->left);
        int rh=height(root->right);
        maxi=max(maxi,(lh+rh));
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
        
        
        // maxi=max(maxi,(lh+rh));
        
        // return 
        
    }
};