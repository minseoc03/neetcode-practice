#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // isPre[a][b] indicates whether a is a prerequisite of b.
        vector<vector<bool>> isPre(
            numCourses, vector<bool>(numCourses, false)
        );

        for (const auto& pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];

            adj[a].push_back(b);
            indeg[b]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : adj[curr]) {
                // curr is a direct prerequisite of next.
                isPre[curr][next] = true;

                // Every prerequisite of curr also precedes next.
                for (int p = 0; p < numCourses; ++p) {
                    if (isPre[p][curr]) {
                        isPre[p][next] = true;
                    }
                }

                indeg[next]--;
                if (indeg[next] == 0) {
                    q.push(next);
                }
            }
        }

        vector<bool> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            answer.push_back(isPre[query[0]][query[1]]);
        }

        return answer;
    }
};