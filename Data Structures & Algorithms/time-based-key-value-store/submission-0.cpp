class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back(timestamp);
        value_map[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        auto it = time_map.find(key);
        if (it == time_map.end()) return "";
        const vector<int>& times = it->second;

        int l = 0, r = static_cast<int>(times.size()) - 1;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (times[mid] <= timestamp) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res == -1 ? "" : value_map[key][res];
    }
private:
    unordered_map<string, vector<int>> time_map;
    unordered_map<string, vector<string>> value_map;
};
