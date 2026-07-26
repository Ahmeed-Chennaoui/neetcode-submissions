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
    int mx=0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return mx;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        mx = max(mx,left+right);
        return 1 + max(left, right);
    }
};
