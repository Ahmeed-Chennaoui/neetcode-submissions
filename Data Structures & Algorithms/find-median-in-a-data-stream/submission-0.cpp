class MedianFinder {
   public:
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int> small;
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        if (!large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }
        if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
        if (large.size() + 1 < small.size()) {
            large.push(small.top());
            small.pop();
        }
    }

    double findMedian() {
        int n = large.size() + small.size();
        if (n % 2)
            return large.size() > small.size() ? large.top() : small.top();
        else
            return (large.top() + small.top()) / 2.0;
    }
};
