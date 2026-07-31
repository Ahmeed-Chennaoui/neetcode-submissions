class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(),nums.end());
        dfs(nums,sub,0);
        return res;

    }
    void dfs(vector<int>& nums,vector<int>& sub,int i){
        if(i>=nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(nums,sub,i+1);
        while(i+1<nums.size()&& nums[i]==nums[i+1])i++;
        sub.pop_back();
        dfs(nums,sub,i+1);
    }

};
