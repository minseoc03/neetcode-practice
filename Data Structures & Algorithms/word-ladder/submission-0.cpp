#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_map<string, vector<string>> pattern;

        for (const string& w : wordList) {
            for (int i = 0; i < w.size(); ++i) {
                string masked = w;
                masked[i] = '*';
                pattern[masked].push_back(w);
            }
        }

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int counter = 1;

        while (!q.empty()) {
            // Process only the words in the current BFS level.
            int levelSize = q.size();

            for (int k = 0; k < levelSize; ++k) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) {
                    return counter;
                }

                for (int i = 0; i < curr.size(); ++i) {
                    string masked = curr;
                    masked[i] = '*';

                    auto it = pattern.find(masked);
                    if (it == pattern.end()) {
                        continue;
                    }

                    for (const string& w : it->second) {
                        // Mark as visited when adding to the queue.
                        if (visited.insert(w).second) {
                            q.push(w);
                        }
                    }

                    // Remove only after processing the entire bucket.
                    pattern.erase(it);
                }
            }

            ++counter;
        }

        return 0;
    }
};