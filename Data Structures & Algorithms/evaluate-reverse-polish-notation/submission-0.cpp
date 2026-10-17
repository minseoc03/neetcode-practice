class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& t : tokens) {
            bool isOperator = (t == "+" || t == "-" || t == "*" || t== "/");
            if (!isOperator) {
                st.push(stoi(t));
                continue;
            }
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();
            switch(t[0]) {
                case '+' : st.push(left + right); break;
                case '-' : st.push(left - right); break;
                case '*' : st.push(left * right); break;
                case '/' : st.push(left / right); break;
            }
        }
        return st.top();
    }
};
