class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;

        backtrack(n, res, curr, 0, 0);
        return res;
    }

    void backtrack(
        int n,
        vector<string>& res,
        string& curr,
        int l,
        int r
    ) {
        if (l == n && r == n) {
            res.push_back(curr);
            return;
        }

        if (l < n) {
            curr.push_back('(');
            backtrack(n, res, curr, l + 1, r);
            curr.pop_back();
        }

        if (r < l) {
            curr.push_back(')');
            backtrack(n, res, curr, l, r + 1);
            curr.pop_back();
        }
    }
};