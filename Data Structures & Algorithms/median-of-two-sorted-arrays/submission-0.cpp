class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1,& b = nums2;
        if (a.size() < b.size()) swap(a, b);
        int n = a.size(), m = b.size();
        int l = 0, r = b.size();
        while (l <= r) {
            int i = (r + l) / 2;
            int j = (n + m+1) / 2 - i;
            int bLeft = i > 0 ? b[i - 1] : INT_MIN;
            int bRight = i < m ? b[i] : INT_MAX;
            int aLeft = j > 0 ? a[j - 1] : INT_MIN;
            int aRight = j < n ? a[j] : INT_MAX;
            if (aLeft <= bRight && bLeft <= aRight) {
                return (n + m) % 2 ? max(aLeft, bLeft)
                                   : (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            } else if (aLeft > bRight)
                l = i + 1;
            else
                r = i - 1;
        }
        return -1;
    }
};
