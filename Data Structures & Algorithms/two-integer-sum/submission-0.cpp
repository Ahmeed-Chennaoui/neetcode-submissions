class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> idx;
        for(int i=0;i<nums.size();i++){
            idx[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(idx.contains(target-nums[i])&& idx[target-nums[i]]!=i)return {i,idx[target-nums[i]]};
        }
        return {};
    }
};
