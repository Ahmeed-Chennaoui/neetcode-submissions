class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int result=0,n=heights.size();
        for(int i=0;i<n;i++){
            int idx=i;
            while(!st.empty() && heights[i]<st.top().first){
                result = max(result,st.top().first * (i-st.top().second));
                idx=st.top().second;
                st.pop();
            
            }
            st.push({heights[i],idx});
        }
        while(!st.empty()){
            result = max(result,st.top().first * (n-st.top().second));
            st.pop();
        }
        return result;
    }
};
