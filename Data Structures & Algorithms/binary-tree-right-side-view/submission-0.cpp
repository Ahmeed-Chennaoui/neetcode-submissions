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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool rightSet= false;
            for(int i=0;i<n;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur){
                    if(!rightSet)res.push_back(cur->val);
                    rightSet=true;
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        return res;
    }
};
