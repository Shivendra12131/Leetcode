class Solution {
    bool traversal(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (root == NULL) return false;
        
        path.push_back(root);
        
        if (root == node) return true;
        
        if (traversal(root->left, node, path) || traversal(root->right, node, path)) {
            return true;
        }
        
        path.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        traversal(root, p, path1);
        traversal(root, q, path2);
        
        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            i++;
        }
        
        return path1[i - 1];
    }
};