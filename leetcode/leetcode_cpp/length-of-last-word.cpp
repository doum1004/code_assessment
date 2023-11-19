class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (res && isspace(s[i]))
                break;
            if (!isspace(s[i]))
                res += 1; 
        }
        return res;        
    }
};