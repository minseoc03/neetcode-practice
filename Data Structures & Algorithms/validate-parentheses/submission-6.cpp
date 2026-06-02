class Solution {
public:
    bool isValid(const string& s) {            // 입력 복사 회피
        if (s.size() & 1) return false;         // 홀수 → 불가능
        vector<char> st;                        // deque 대신 contiguous
        st.reserve(s.size());                   // 재할당 회피
        for (char c : s) {
            switch (c) {
                case '(': st.push_back(')'); break;   // 기대 닫힘 괄호 push
                case '{': st.push_back('}'); break;
                case '[': st.push_back(']'); break;
                default:                               // 닫힘 괄호
                    if (st.empty() || st.back() != c) return false;
                    st.pop_back();
            }
        }
        return st.empty();
    }
};