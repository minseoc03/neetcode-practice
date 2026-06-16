class LRUCache {
private:
    struct Node {
        int key;
        int val;
        int prev;
        int next;
    };
    unordered_map<int,int> index; //key -> index
    vector<Node> pool;
    int head = -1;
    int tail = -1;
    int freehead;
    int cap;

    void unlink(int i) {
        int p = pool[i].prev;
        int n = pool[i].next;
        if (p == -1) head = n; else pool[p].next = n;
        if (n == -1) tail = p; else pool[n].prev = p;
    }
    void pushBack(int i) {
        pool[i].prev = tail;
        pool[i].next = -1;
        if (tail != -1) pool[tail].next = i; else head = i;
        tail = i;
    }

public:
    LRUCache(int capacity) : pool(capacity), cap(capacity) {
        for (int i = 0; i < cap; ++i) {
            pool[i].next = i + 1;
        }
        freehead = 0;
        pool[cap - 1].next = -1;
    }
    
    int get(int key) {
        auto it = index.find(key);
        if (it == index.end()) return -1;
        int i = it->second;
        unlink(i); pushBack(i);
        return pool[i].val;
    }
    
    void put(int key, int value) {
        if (auto it = index.find(key); it != index.end()) {
            int i = it->second;
            unlink(i); pushBack(i);
            pool[i].val = value;
            return;
        }
        int i;
        if (freehead == -1) {
            i = head;
            index.erase(pool[i].key);
            unlink(i);
        }
        else {
            i = freehead;
            freehead = pool[i].next;
        }
        index[key] = i;
        pool[i].key = key;
        pool[i].val = value;
        pushBack(i);
    }
};
