class Solution {
   public:
    unordered_set<int> visit;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> pre;
        for (auto x : prerequisites) pre[x[0]].push_back(x[1]);
        for (auto const [key, val] : pre) {
            if (!dfs(key, pre)) return false;
        }
        return true;
    }
    bool dfs(int n, unordered_map<int, vector<int>>& pre) {
        if (visit.count(n)) return false;
        if (pre[n].empty()) return true;
        visit.insert(n);
        for (auto x : pre[n]) {
            if (!dfs(x, pre)) return false;
        }
        visit.erase(n);
        pre[n] = {};
        return true;
    }
};
