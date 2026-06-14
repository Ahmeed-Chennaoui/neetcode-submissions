class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res =0,n=nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                int curNum=nums[i],curCount=1;
                s.erase(curNum);
                while(s.find(curNum-1)!=s.end()){
                    s.erase(curNum-1);
                    curNum-=1;
                    curCount++;
                }
                curNum=nums[i];
                while(s.find(curNum+1)!=s.end()){
                    s.erase(curNum+1);
                    curNum+=1;
                    curCount++;
                }
                res=max(res,curCount);


            }
        }
        return res;
    }
};
