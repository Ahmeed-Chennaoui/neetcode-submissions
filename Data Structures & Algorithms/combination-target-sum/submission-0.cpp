class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, 0, cur, 0, target);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, int i, vector<int>& cur, int curSum,
             int target) {
        if (curSum == target) {
            res.push_back(cur);
            return;
        }
        if (curSum > target || i >= nums.size()) return;
        cur.push_back(nums[i]);
        curSum += nums[i];
        dfs(nums, res, i, cur, curSum, target);
        cur.pop_back();
        curSum -= nums[i];
        dfs(nums, res, i+1, cur, curSum, target);
    }
};
