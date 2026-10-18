class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& v = m[key];

        auto it = m.find(key);
        if (it == m.end()) return "";

        if (v.empty() || v[0].first > timestamp) return "";
        int l = 0;
        int r = v.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (v[mid].first <= timestamp) l = mid;
            else r = mid - 1;
        }
        return v[l].second;
    }
};
