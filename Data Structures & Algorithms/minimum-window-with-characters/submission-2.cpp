class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size(), l = 0, resStart = -1;
        unordered_map<char, int> countT, window;
        for (auto c : t) countT[c]++;
        int have = 0, need = countT.size(), resLen = INT_MAX;
        for (int r = 0; r < n; r++) {
            window[s[r]]++;
            if (countT.find(s[r]) != countT.end() && window[s[r]] == countT[s[r]]) have++;
            while (have == need && l <= r) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    resStart = l;
                }
                window[s[l]]--;
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) have--;
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};
