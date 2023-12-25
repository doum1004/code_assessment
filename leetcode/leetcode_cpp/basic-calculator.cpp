/*
https://leetcode.com/problems/basic-calculator

Solution2. Stack
https://leetcode.com/problems/basic-calculator/solutions/62377/16-ms-solution-in-c-with-stacks/?envType=study-plan-v2&envId=top-interview-150
time: o(n)
space: o(n)

(1+(4+5+2)-3)+(6+8)
total = 0
n = 0
o = +

total = 1
n = 0
o = +

total = 0
n = 0 1
o = + +

total = 4 + 5 + 2 = 11
n = 0 1
o = + +

total = +11 + 1 = 12
n = 0
o = +

total = 12 - 3
n = 0
o = +

total = +9 + 0 = 0
n
o

total = 0
n 9
o +

total = 6+8 = 14
n 9
o +

total = +14 + 9
total = 25


*/
class Solution {
public:
    int cal(vector<int>& nq, vector<char>& oq) {
        int res = nq[0];
        int l = 1, r = 0;
        while (l < nq.size() && r < oq.size()) {
            switch (oq[r]) {
                case '+':
                    res += nq[l];
                    break;
                case '-':
                    res -= nq[l];
                    break;
            }
            l += 1;
            r += 1;
        }
        return res;
    }

    int calculate_1(string& s) {
        vector<vector<int>> nq(1);
        vector<vector<char>> oq(1);
        int num = 0;
        bool hasNumber = false;
        for (auto c:s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                hasNumber = true;
            }
            else {
                if (hasNumber) nq.back().push_back(num);
                if (c == '(') {
                    nq.push_back({});
                    oq.push_back({});
                }
                else if (c == ')') {
                    int res = cal(nq.back(), oq.back());
                    nq.pop_back();
                    oq.pop_back();
                    nq.back().push_back(res);                
                }
                else if (!isspace(c)){
                    if (!nq.back().size()) nq.back().push_back(0);
                    oq.back().push_back(c);
                }
                num = 0;
                hasNumber = false;
            }
        }
        if (hasNumber) nq.back().push_back(num);
        return cal(nq.back(), oq.back());
    }

    int calculate_2(string& s) {
        stack<int> ns, os;
        int total = 0, num = 0, sign = 1;
        for (auto c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else {
                total += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                else if (c == '-') sign = -1;
                else if (c == '(') {
                    ns.push(total);
                    os.push(sign);
                    total = 0;
                    sign = 1;
                }
                else if (c == ')') {
                    total = total * os.top() + ns.top();
                    os.pop(); ns.pop();
                }
            }
        }
        total += num * sign;
        
        return total;
    }
    
    int calculate(string s) {
        return calculate_2(s);
    }
};