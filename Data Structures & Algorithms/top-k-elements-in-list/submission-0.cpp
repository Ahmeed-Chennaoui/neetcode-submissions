class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        map<int,vector<int>> occ;
        vector<int> res;
        for(int i=0;i<nums.size();i++)freq[nums[i]]++;
        for(auto freqPair: freq)occ[freqPair.second].push_back(freqPair.first);
        for (auto it = occ.rbegin();it!=occ.rend()&& k>0;it++){
            // I'm pushing the whole array because the problem statement is saying the answer is unique 
            // so if there are multiple with same frequency, k will always be such that they will all be included
            res.insert(res.end(),(it->second).begin(),(it->second).end());
            k-=(it->second).size();
        }
        return res;
    }
};
