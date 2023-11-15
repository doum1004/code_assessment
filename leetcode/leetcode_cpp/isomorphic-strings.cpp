/*
https://leetcode.com/problems/summary-ranges

sol1. pointer
time: o(n)
space: o(n)

0 1 2 4 5 7
          i
f: 0, c: 0
f: 0, c: 1
f: 0, c: 2, f: 4, c: 0. s = "0->2"
f: 4, c: 1. f: 7, c: 0. s = "4->5"
f: 7, c: 0. s = "7"

sol2. sliding door
time: o(n)
space: o(1)

0 1 2 4 5 7
l
  r

loop r<=nums.size
  loop r<nums.size and nums[r-1] + 1 == nums[r]
    r++
  string s
  if (r - 1 == l)
    s = to_string(nums(l))
  else
    s = to_String(nums(l)) + "->" + to_string(nums[r - 1])
  l = r
    


*/

class Solution {
public:
    vector<string> summaryRanges_1(vector<int>& nums) {
        vector<string> res;
        if (!nums.size()) return res;

        int n = nums[0];
        int c = 0;
        for (int i=1; i<=nums.size(); ++i) {
            if (i < nums.size() && n + c + 1 == nums[i]) {
                c++;
            }
            else {
                string s = to_string(n);
                if (c != 0)
                    s += "->" + to_string(n+c);
                res.push_back(s);
                
                if (i != nums.size()) {                    
                    n = nums[i];
                    c = 0;
                }
            }
        }
        return res;
    }

    vector<string> summaryRanges_2(vector<int>& nums) {
        if (!nums.size()) return {};
        vector<string> res;
        int l = 0, r = 1;
        int n = nums.size();
        while (r <= n) {
            while (r < n && nums[r - 1] + 1 == nums[r])
                r++;
            
            if (r - 1 == l)
                res.push_back(to_string(nums[l]));
            else
                res.push_back(to_string(nums[l]) + "->" + to_string(nums[r-1]));

            l = r;
            r++;
        }

        return res;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        return summaryRanges_2(nums);
    }
};