class Solution {
   public:
    unordered_set<int> visit;
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) return false;
        vector<vector<int>> adj(n);
        for (const auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!dfs(i, -1, adj)) return false;
        }
        return true;
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj) {
        if (adj[node].empty()) return true;
        if (visit.count(node)) return false;
        visit.insert(node);
        for (auto x : adj[node]) {
            if (x == parent) continue;
            if (!dfs(x, node, adj)) return false;
        }
        visit.erase(node);
        return true;
    }
};
