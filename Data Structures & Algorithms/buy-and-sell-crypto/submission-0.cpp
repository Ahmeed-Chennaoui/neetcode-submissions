class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0,curMin=100;
        for(int i=0;i<prices.size();i++){
            curMin=min(curMin,prices[i]);
            res=max(res,prices[i]-curMin);
        }
        return max(res,0);
    }
};
