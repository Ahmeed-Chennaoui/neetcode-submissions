class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        set<vector<int>> seen;
        vector<vector<int>> res;
        for(int i =0;i<n;i++)mp[nums[i]].push_back(i);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curSum = nums[i]+nums[j];
                if(mp.find(-curSum)!=mp.end()){
                    for(auto x: mp[-curSum]){
                        vector<int> curVect= {nums[i],nums[j],nums[x]};
                        sort(curVect.begin(),curVect.end());
                        if(x>j && seen.find(curVect)==seen.end()){
                            
                            res.push_back(curVect);
                            seen.insert(curVect);
                        }
                    }
                }
            }
        }
        return res;
    }
};
