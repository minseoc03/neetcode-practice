class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> free;
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
        > busy; // {end time, room number}

        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        for (auto& m : meetings) {
            while (!busy.empty() && busy.top().first <= m[0]) {
                auto [endTime, room] = busy.top();
                busy.pop();
                free.push(room);
            }
            if (!free.empty()) {
                busy.push({m[1], free.top()});
                count[free.top()]++;
                free.pop();
            }
            else {
                auto [endTime, room] = busy.top();
                busy.pop();
                busy.push({endTime + (m[1] - m[0]), room});
                count[room]++;
            }
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};