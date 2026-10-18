class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;

        backtrack(s, res, curr, 0);
        return res;
    }

    void backtrack(
        const string& s,
        vector<vector<string>>& res,
        vector<string>& curr,
        int i
    ) {
        if (i == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            if (!isPalindrome(s, i, j)) {
                continue;
            }

            curr.push_back(s.substr(i, j - i + 1));
            backtrack(s, res, curr, j + 1);
            curr.pop_back();
        }
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};