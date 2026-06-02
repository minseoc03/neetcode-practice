class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> p{
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> st;
        for (const auto& c : s) {
            auto it = p.find(c);
            if (it != p.end()) {
                if (st.empty() || st.top() != it->second)
                    return false;
                else
                    st.pop();
            }
            else
                st.push(c);
        }
        return st.empty();
    }
};
