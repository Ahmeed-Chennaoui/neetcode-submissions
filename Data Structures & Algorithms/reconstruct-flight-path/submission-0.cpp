class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for (auto& [src, dests] : adj) {
            sort(dests.rbegin(), dests.rend());
        }
        vector<string> itinerary;
        dfs("JFK", adj, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

   private:
    void dfs(string airport, unordered_map<string, vector<string>>& adj,
             vector<string>& itinerary) {
        while (!adj[airport].empty()) {
            string next = adj[airport].back();
            adj[airport].pop_back();
            dfs(next, adj, itinerary);
        }

        itinerary.push_back(airport);
    }
};