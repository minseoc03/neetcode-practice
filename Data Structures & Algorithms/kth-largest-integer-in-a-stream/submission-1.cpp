class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int capacity;
    vector<int> n;
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for (int i : nums) {
            minheap.push(i);
            if (minheap.size() > capacity) {
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if (minheap.size() > capacity) {
            minheap.pop();
        }
        return minheap.top();
    }
};
