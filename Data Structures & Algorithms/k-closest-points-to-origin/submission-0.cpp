class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] * lhs[0] + lhs[1] * lhs[1] > rhs[0] * rhs[0] + rhs[1] * rhs[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap;
        vector<vector<int>> res;
        for (auto p : points) {
            minHeap.push(p);
        }
        while (k--) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }
};
