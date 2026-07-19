class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            heap.push({nums[i], i});
        }
        res.push_back(heap.top().first);
        for (int i = 0; i < n - k; i++) {
            int toAdd = i + k;
            heap.push({nums[toAdd], toAdd});
            while (heap.top().second < i + 1) {
                heap.pop();
            }
            res.push_back(heap.top().first);
        }
        return res;
    }
};
