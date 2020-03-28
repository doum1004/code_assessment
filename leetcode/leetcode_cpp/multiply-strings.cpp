#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/multiply-strings/

- Solution1. convert string to int (not accepted due to size of input is larger than capacity of integer

- Solution2. iterate nums and multiply to accumulate result
- time: o(n*m)
- space: o(n*m) but it can be o(1) if we use answer as accumlation

*/

class Solution {
public:
    int stringToInt(string num) {
        int res = 0;
        for (int i=0; i<num.size(); ++i) {
            res = res * 10  + (num[i] - '0');
        }
        return res;
    }
    
    string intToString(int n) {
        string res;
        while (n>0) {
            res = to_string(n%10) + res;
            n /= 10;
        }
        return res;
    }
    
    string multiply_convertInt_manual(string& num1, string& num2) {
        int n1 = stringToInt(num1);
        int n2 = stringToInt(num2);
        return intToString(n1 * n2);
    }
    
    string multiply_convertInt_builtin(string& num1, string& num2) {
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        return to_string(n1 * n2);
    }
    
    string multiply_instring(string& num1, string& num2) {
        int nb_1 = num1.size(), nb_2 = num2.size();
        vector<int> s(nb_1 * nb_2 + 1, 0); // it can be string directly
        
        for (int i=nb_1-1; i>=0; --i) {
            int n1 = num1[i] - '0';
            for (int j=nb_2-1; j>=0; --j) {
                int n2 = num2[j] - '0';
                int result = n1 * n2;
                
                int p1 = nb_1 - i - 1;
                int p2 = nb_2 - j - 1;
                
                s[p1+p2] += result;
                if (s[p1+p2] > 9) {
                    s[p1+p2+1] += s[p1+p2] / 10;
                    s[p1+p2] %= 10;
                }
            }
        }
        string res;
        bool digit = false;
        for (int i=s.size()-1; i>=0; --i) {
            if (!digit && s[i] == 0) continue;
            if (!digit) digit = true;
            res += char(s[i] + '0');
        }
        return res == "" ? "0" : res;
    }
    
    string multiply(string num1, string num2) {
        //return multiply_convertInt_builtin(num1, num2);
        //return multiply_convertInt_manual(num1, num2);
        return multiply_instring(num1, num2);
    }
};

int main()
{
    assert(Solution().multiply("2", "3") == ("6"));
    assert(Solution().multiply("123", "456") == ("56088"));
    assert(Solution().multiply("10000000000000000", "10000000000000000") == ("100000000000000000000000000000000"));

    return 0;
}
