class LRUCache {
private:
    // key = key; value = value and node
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        order.splice(order.end(), order, cache[key].second);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        }
        else if (cache.size() == capacity) {
            int lru = order.front(); // pop out lru key
            order.pop_front();
            cache.erase(lru); // erase key from cache map
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};