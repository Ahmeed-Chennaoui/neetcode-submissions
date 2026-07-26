class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mp[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        vector<pair<int, string>> values = mp[key];
        int l = 0, r = values.size() - 1;
        if (values.empty()) return "";
        while (l < r) {
            int m = l + (r - l) / 2;
            if (values[m].first == timestamp)
                return values[m].second;
            else if (values[m].first > timestamp)
                r = m - 1;
            else
                l = m + 1;
        }
        if (values[l].first > timestamp)
            return l > 0 ? values[l - 1].second : "";
        else
            return values[l].second;
    }
};
