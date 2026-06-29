class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int res=0;
        int l=0,r=n-1;
        while(l<r){
            res=max(res,min(heights[l],heights[r])*(r-l));
            if(heights[l]>heights[r])r--;
            else l++;
        }
        return res;
    }
};
