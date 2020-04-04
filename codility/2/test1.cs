using System.Diagnostics;
class HelloWorld {
    

    public class Solution {
        public int test1_solution1(int N) {
            var l = new List<int>();
            while (N>0) {
                l.Add(N%10);
                N /= 10;
            }
            l.Sort();
            
            int res = 0;
            for (int i=l.Count-1; i>=0; --i) {
                res = res*10 + l[i];
            }
            return res;
        }
        
        public int test1_solution2(int N) {
            int[] bucket = new int[10];
            
            var s = N.ToString();
            var res = 0;
            foreach (var c in s) {
                bucket[c - '0']++;
            }
            
            for (int i=9; i>=0; --i) {
                while (bucket[i]-- > 0) {
                    res = res * 10 + i;
                }
            }
            
            return res;
        }
        
        public int test1(int N) {
            //return test1_solution1(N);
            return test1_solution2(N);
        }
    }
    
    static void Main() {
        System.Console.WriteLine(new Solution().test1(123));
        System.Console.WriteLine(new Solution().test1(316));
    }
}