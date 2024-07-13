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
    int height(TreeNode*node,int &maxi){
        if(node==NULL) return 0;
        int lh=height(node->left,maxi);
        int rh=height(node->right,maxi);
        maxi=max(maxi,(lh+rh));
        return 1+max(lh,rh);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=0;
        height(root,maxi);
        return maxi;
        // return 
        // int lh=height(root->left);
        // int rh=height(root->right);
        // return 
        
    }
};