class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> chosen(nums.size(), false);
        vector<int> cur;
        dfs(nums, chosen, cur);
        return res;
    }
    void dfs(vector<int>& nums, vector<bool>& chosen, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!chosen[i]) {
                cur.push_back(nums[i]);
                chosen[i] = true;
                dfs(nums, chosen, cur);
                chosen[i] = false;
                cur.pop_back();
            }
        }
    }
};
