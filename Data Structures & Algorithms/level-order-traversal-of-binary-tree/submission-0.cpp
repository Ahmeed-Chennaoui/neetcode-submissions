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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int n = q.size();
            vector<int> curLevel = {};
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    curLevel.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            if (!curLevel.empty()) res.push_back(curLevel);
        }
        return res;
    }
};
