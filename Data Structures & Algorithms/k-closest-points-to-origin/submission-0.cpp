class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        for (auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            minheap.push({dist, p[0], p[1]});
        }
        vector<vector<int>> res;
        while (k-- > 0) {
            auto& top = minheap.top();
            res.push_back({top[1], top[2]});
            minheap.pop();
        }
        return res;
    }
};

// I can use minheap for here
// in the heap, I would insert array<int,3> where first element represent the distance,
// second element represent the x coordinate and third one represent y coordinate
// then I can pop out k elements from the heap and return those!