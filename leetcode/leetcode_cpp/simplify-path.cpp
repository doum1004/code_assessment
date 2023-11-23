/*
https://leetcode.com/problems/simplify-path

Solution1. stack
time: o(n)
space: o(n)

1. iterate path
2. add strings into temp
3. if it hits '/' check conditions of temp
- '..' pop the last (stack needed)
- '.' or '' skip
- clean temp
- continue iteration
4. iterate stack to build answer

*/

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        
        string temp;
        for (int i=0; i<path.size(); ++i) {
            if (path[i] == '/') {
                if (temp == "..") {
                    if (!st.empty()) st.pop();
                }
                else if (temp != "." && temp != "") {
                    st.push(temp);
                }
                temp = "";
                continue;
            }
            temp += path[i];
        }

        string res;
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res == "" ? "/" : res;
    }
};