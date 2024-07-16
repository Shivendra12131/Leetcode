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
public:
    // Helper function to find the LCA
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue) {
        if (!root || root->val == startValue || root->val == destValue) return root;
        TreeNode* left = findLCA(root->left, startValue, destValue);
        TreeNode* right = findLCA(root->right, startValue, destValue);
        if (left && right) return root;
        return left ? left : right;
    }

    // Helper function to find path from root to target
    bool findPath(TreeNode* root, int target, string& path) {
        if (!root) return false;
        if (root->val == target) return true;
        if (root->left && findPath(root->left, target, path)) {
            path.push_back('L');
            return true;
        }
        if (root->right && findPath(root->right, target, path)) {
            path.push_back('R');
            return true;
        }
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string pathToStart, pathToDest;
        findPath(lca, startValue, pathToStart);
        findPath(lca, destValue, pathToDest);
        for (char& ch : pathToStart) ch = 'U';  // Replace all characters in pathToStart with 'U'
        reverse(pathToStart.begin(), pathToStart.end());
        reverse(pathToDest.begin(), pathToDest.end());
        return pathToStart + pathToDest;
    }
};