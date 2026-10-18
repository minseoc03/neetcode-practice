class Solution {
public:
    vector<vector<int>> combinationSum2(
        vector<int>& candidates, int target
    ) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> comb;
        backtrack(candidates, target, res, comb, 0, 0);
        return res;
    }

    void backtrack(
        const vector<int>& candidates,
        int target,
        vector<vector<int>>& res,
        vector<int>& comb,
        int start,
        int sum
    ) {
        if (sum == target) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i < static_cast<int>(candidates.size()); ++i) {

            // 같은 단계에서 같은 값으로 시작하는 중복 분기 제거
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (sum + candidates[i] > target) {
                break;
            }

            comb.push_back(candidates[i]);

            backtrack(
                candidates,
                target,
                res,
                comb,
                i + 1,
                sum + candidates[i]
            );

            comb.pop_back();
        }
    }
};