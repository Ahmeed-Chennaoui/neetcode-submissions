class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int res=0,l=0,r=0;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
                res=max(res,r-l);
            }
            else{
                while(s[l]!=s[r]){
                    st.erase(s[l]);
                    l++;
                }
                l++;
                r++;
            }
        }
        return res;

    }
};
