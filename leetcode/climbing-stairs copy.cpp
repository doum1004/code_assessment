#include <iostream>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/integer-to-english-words/

// Solution1. Divide and conquer
// time: o(n). output is proportinal to the number of n
// space: o(1)

1. do for billion, million, thousand, and rest
2. make function table for 0~9, 10~19, 20~90.
3. do for three digits (hundred) and do for two digits

*/

class Solution {
public:
    string numberToWords(int num) {
        if (num < 10) return one(num);
        
        int rest = num;
        int billion = num / 1000000000;
        rest -= billion * 1000000000;
        int million = rest / 1000000;
        rest -= million * 1000000;
        int thousand = rest / 1000;
        rest -= thousand * 1000;
        
        string result = "";
        if (billion > 0) {
            if (!result.empty()) result += " ";
            result += three(billion) + " Billion";
        }
        if (million > 0) {
            if (!result.empty()) result += " ";
            result += three(million) + " Million";
        }
        if (thousand > 0) {
            if (!result.empty()) result += " ";
            result += three(thousand) + " Thousand";
        }
        if (rest > 0) {
            if (!result.empty()) result += " ";
            result += three(rest);
        }
        
        return result;
    }
    
private:
    string one(int num) {
        switch (num) {
            case 0: return "Zero";
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        return "";
    }
    
    string tenToNineTeen(int num) {
        switch (num) {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        return "";
    }
    
    string ten(int num) {
        switch (num) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
        }
        return "";
    }
    
    string two(int num) {
        if (num == 0) return "";
        else if (num < 10) return one(num);
        else if (num < 20) return tenToNineTeen(num);
        else {
            int tennder = num / 10;
            int rest = num - tennder * 10;
            
            string res = "";
            if (tennder > 0) {
                res += ten(tennder);
            }
            if (rest > 0) {
                if (!res.empty()) res += " ";
                res += one(rest);
            }
            return res;
        }
    }
    
    string three(int num) {
        int hundred = num / 100;
        int rest = num - hundred * 100;
        string res = "";
        if (hundred > 0) {
            res += one(hundred) + " Hundred";
        }
        if (rest > 0) {
            if (!res.empty()) res += " ";
            res += two(rest);
        }
        
        return res;
    }
};

int main()
{
    assert(Solution().numberToWords(123) == ("One Hundred Twenty Three"));
    assert(Solution().numberToWords(12345) == ("Twelve Thousand Three Hundred Forty Five"));
    assert(Solution().numberToWords(1234567) == ("One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"));
    assert(Solution().numberToWords(1234567891) == ("One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"));
    return 0;
}