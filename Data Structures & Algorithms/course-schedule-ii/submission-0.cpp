class Solution {
   public:
    vector<int> res;
    unordered_map<int, vector<int>> pre;
    unordered_set<int> visit, sol;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto x : prerequisites) {
            pre[x[0]].push_back(x[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return {};
        }
        return res;
    }
    bool dfs(int n) {
        if (visit.count(n)) return false;
        if (pre[n].empty()) {
            if (!sol.count(n)) res.push_back(n);
            sol.insert(n);
            return true;
        }
        visit.insert(n);
        for (auto x : pre[n]) {
            if (!dfs(x)) return false;
        }
        res.push_back(n);
        sol.insert(n);
        visit.erase(n);
        pre[n] = {};
        return true;
    }
};
