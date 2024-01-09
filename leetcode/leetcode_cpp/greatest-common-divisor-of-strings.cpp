class Solution {
public:
    int findGCD(int a, int b) {
        if (b == 0) return a;
        return findGCD(b, a%b);
    }
    string gcdOfStrings_1(string& str1, string& str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, findGCD(str1.size(), str2.size()));
    }
    string gcdOfStrings_2(string& str1, string& str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
    string gcdOfStrings(string str1, string str2) {
        return gcdOfStrings_1(str1, str2);
    }
};