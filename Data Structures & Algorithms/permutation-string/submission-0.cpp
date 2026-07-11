class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int l = 0, r = 0, n = s2.size();
        unordered_map<char, int> mp1, mp2;
        for (auto x : s1) mp1[x]++;
        while (r < n) {
            while (r - l + 1 <= s1.size()) {
                mp2[s2[r]]++;
                r++;
            }
            if (mp1 == mp2) return true;
            mp2[s2[l]]--;
            if (mp2[s2[l]] == 0) mp2.erase(s2[l]);
            l++;
        }
        return false;
    }
};
