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
    bool preorder(TreeNode*p,TreeNode*q)
    {
        if(p==NULL||q==NULL) return p==q;
        if(p->val!=q->val) return false;
        return preorder(p->left,q->left)&&
        preorder(p->right,q->right);

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return preorder(p,q);
        
    }
};