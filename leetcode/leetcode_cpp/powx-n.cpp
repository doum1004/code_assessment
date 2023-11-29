/*
https://leetcode.com/problems/powx-n

Solution1. Recursion. o(n)/o(n)
Solution2. Iteration. o(n)/o(1)
Soluiton3. Recursion. Every 2 in n. o(logn) / o(logn)
Soluiton4. Iteration. Every 2 in n. o(logn) / o(1)

*/
class Solution {
public:
    double myPow_1_recurse(double x, int n) {
        if (n == 0) return 1;
        return x * myPow_1_recurse(x, n - 1);
    }

    double myPow_1(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MAX) return x == 1 ? 1 : x == -1 ? -1 : 0;
        if (n == INT_MIN) return abs(x) == 1 ? 1 : 0;
        bool isNagative = n < 0;
        n = abs(n);
        double res = myPow_1_recurse(x, n);
        if (isNagative)
            res = 1.0 / res;
        return res;
    }

    double myPow_2(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MAX) return x == 1 ? 1 : x == -1 ? -1 : 0;
        if (n == INT_MIN) return abs(x) == 1 ? 1 : 0;

        bool isNagative = n < 0;
        n = abs(n);

        double res = 1;
        while (n-- > 0) {
            res *= x;
        }
        if (isNagative)
            res = 1.0 / res;
        return res;
    }

    double myPow_3(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            n = abs(n);
            x = 1.f / x;
        }
        if (n % 2 == 0) {
            return myPow_3(x * x, n / 2);
        } else {
            return x*myPow_3(x, n-1);
        }
    }

    double myPow_4(double x, int n) {
        bool isNegative = n < 0;
                
        long long nn = n;
        if(nn < 0) nn = abs(nn);

        double num = 1;
        while(nn>0){
            if(nn%2==1){
                num = num * x;
                nn--;
            }
            else{
                x = x*x;
                nn/=2;
            }
        }
        if(isNegative){
            num = 1.0/num;
        }
        return num; 
    }
    
    double myPow(double x, int n) {
        return myPow_4(x, n);
    }
};
