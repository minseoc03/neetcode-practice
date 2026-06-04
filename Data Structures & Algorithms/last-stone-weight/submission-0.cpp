class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int i = 0; i < stones.size(); ++i) {
            heap.push(stones[i]);
        }
        while (heap.size() > 1) {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            if (a < b) {
                heap.push(b-a);
            }
            else if (a > b) {
                heap.push(a-b);
            }
        }
        return heap.size() == 1 ? heap.top() : 0;
    }
};

// one maxheap a -> tracking all the stones
// [2,3,6,2,4]
// a = [2,2,3,4,6]

// pop out 2 stones from a and smash them
// re-push the after-smash stone into the heap
// how to track the stone index?
// then, I think I can have pair<weight, index> as a member of the heap
// priority_queue<pair<weight, index>>

// while (maxheap.size() > 1) {