class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            if (st.empty())
                st.push({temperatures[i], i});
            else {
                if (temperatures[i] <= st.top().first)
                    st.push({temperatures[i], i});
                else {
                    while (!st.empty() && temperatures[i] > st.top().first) {
                        result[st.top().second] = i - st.top().second;
                        st.pop();
                    }
                    st.push({temperatures[i], i});
                }
            }
        }
        return result;
    }
};
