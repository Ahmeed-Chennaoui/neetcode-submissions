class Solution {
   public:
    vector<int> cache;
    int rob(vector<int>& nums) {
        cache.resize(nums.size(), INT_MIN);
        return max(dfs(0, nums), dfs(1, nums));
    }
    int dfs(int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (cache[i] != INT_MIN) return cache[i];
        cache[i] = nums[i] + max(dfs(i + 2, nums), dfs(i + 3, nums));
        return cache[i];
    }
};
