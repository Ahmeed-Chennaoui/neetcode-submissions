class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size(), res = 1;
        vector<int> freq(26, 0);
        freq[s[l] - 'A'] += 1;

        while (r + 1 < n) {
            r++;
            freq[s[r] - 'A'] += 1;
            if (r - l + 1 <= k + mostFrequent(freq)) res = max(res, r - l + 1);

            while (l < n && r - l + 1 > k + mostFrequent(freq)) {
                freq[s[l] - 'A'] -= 1;
                l++;
            }
        }
        return res;
    }
    int mostFrequent(vector<int>& v) {
        int res = 0;
        for (auto x : v) res = max(res, x);
        return res;
    }
};
