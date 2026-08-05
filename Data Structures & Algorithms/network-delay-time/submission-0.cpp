class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        unordered_set<int> visited;
        for (const auto& time : times) {
            edges[time[0]].push_back({time[1], time[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        int t = 0;
        while (!pq.empty()) {
            auto [w, n] = pq.top();
            pq.pop();
            if (visited.count(n)) continue;
            visited.insert(n);
            t = w;
            for (auto e : edges[n]) {
                if (!visited.count(e.first)) {
                    pq.push({w + e.second, e.first});
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
