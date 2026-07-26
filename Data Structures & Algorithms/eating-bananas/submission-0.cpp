class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MIN, res = INT_MAX;
        for (auto x : piles) r = max(r, x);
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cur = 0;
            for (auto x : piles) cur += x / m + (x % m ? 1 : 0);
            if (cur <= h) {
                res = m;
                r = m - 1;
            } else
                l = m + 1;
        }
       return res;
    }
};
