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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int width = 0;
        
        while (!q.empty()) {
            int n = q.size();
            unsigned long long mini = q.front().second;
            unsigned long long firstval, lastval;
            
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front().first;
                unsigned long long val = q.front().second - mini;
                
                q.pop();
                
                if (temp->left) q.push({temp->left, 2 * val + 1});
                if (temp->right) q.push({temp->right, 2 * val + 2});
                if (i == 0) firstval = val;
                if (i == n - 1) lastval = val;
            }
            width = max(width, static_cast<int>(lastval - firstval + 1));
        }
        return width;
    }
};