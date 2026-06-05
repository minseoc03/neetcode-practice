class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> freq = {};
        priority_queue<int> maxheap;
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        int numTasks = tasks.size();
        for (int f : freq) {
            if (f != 0)
                maxheap.push(f);
        }
        int time = 0;
        while(!maxheap.empty()) {
            int cycle = n+1;
            vector<int> store;
            int taskCount = 0;
            while(cycle-- && !maxheap.empty()) {
                int task = maxheap.top();
                maxheap.pop();
                taskCount++;
                if (task > 1)
                    store.push_back(task);
            }
            for (int s : store) {
                maxheap.push(s - 1);
            }
            time += (maxheap.empty() ? taskCount : n + 1);
        }
        return time;
    }
};

