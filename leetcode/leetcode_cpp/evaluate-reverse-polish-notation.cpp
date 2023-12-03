/*
https://leetcode.com/problems/evaluate-reverse-polish-notation

Solution1. Stack
time: o(n)
space: o(n)

Stack numbers and pop 2 nums for operation

*/
class Solution {
public:
    int evalRPN_1(vector<string>& tokens) {
        vector<int> st;
        for (auto& token:tokens) {            
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                auto v2 = st.back(); st.pop_back();
                auto v1 = st.back(); st.pop_back();
                auto cal = 0;
                if (token == "+")
                    cal = v1 + v2;
                else if (token == "-")
                    cal = v1 - v2;
                else if (token == "*")
                    cal = v1 * v2;
                else if (token == "/")
                    cal = v1 / v2;
                st.push_back(cal);
            }
            else {
                st.push_back(stoi(token));
            }
        }
        return st.front();
    }

    int evalRPN_2(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> m = {
            {"+", [] (int a, int b) { return a+b; }},
            {"-", [] (int a, int b) { return a-b; }},
            {"/", [] (int a, int b) { return a/b; }},
            {"*", [] (int a, int b) { return a*b; }}
        };

        stack<int> st;
        for (auto& t:tokens) {
            if (m.count(t)) {
                auto v2 = st.top(); st.pop();
                auto v1 = st.top(); st.pop();
                st.push(m[t](v1, v2));
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }

    int evalRPN(vector<string>& tokens) {
        return evalRPN_2(tokens);
    }
};