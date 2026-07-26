class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> openCloseMapping = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for (auto c : s) {
            if (openCloseMapping.find(c) != openCloseMapping.end())
                st.push(c);
            else if (!st.empty()) {
                char neededClosing = openCloseMapping[st.top()];
                if (neededClosing != c)
                    return false;
                else
                    st.pop();
            } else
                return false;
        }
        return st.empty();
    }
};
