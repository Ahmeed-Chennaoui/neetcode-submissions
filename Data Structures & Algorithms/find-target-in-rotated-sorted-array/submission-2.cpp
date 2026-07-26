class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m =(r+l)/2;
            if(nums[m]>nums[r])l=m+1;
            else r = m;
        }
        int L=0,R=l-1;
        while(L<=R){
            int m = L+ (R-L)/2;
            if(nums[m]<target)L=m+1;
            else if(nums[m]==target)return m;
            else R=m-1;
        }
        L=l,R=nums.size()-1;
         while(L<=R){
            int m = L+ (R-L)/2;
            if(nums[m]<target)L=m+1;
            else if(nums[m]==target)return m;
            else R=m-1;
        }
        return -1;
    }
};
