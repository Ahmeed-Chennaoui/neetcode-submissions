class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, res, cur, 0, 0, target);
        return res;
    }
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& cur, int i, int curSum,
             int target) {
        if (curSum == target) {
            res.push_back(cur);
            return;
        }
        if (i >= candidates.size() || curSum > target) return;
        if (curSum + candidates[i] > target) return;
        cur.push_back(candidates[i]);
        dfs(candidates, res, cur, i + 1, curSum + candidates[i], target);
        cur.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++;
        dfs(candidates, res, cur, i + 1, curSum, target);
    }
};
